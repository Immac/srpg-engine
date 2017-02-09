#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>

using namespace SrpgEngine::Framework::Lua;
using SrpgEngine::Framework::string;

void SrpgEngine::S2dge::Simple2DGraphicsEngine::Initialize(Game::GameObject &settings)
{
	int video_width, video_height, frame_limit;
	bool vsync;
	string window_title;

	video_width = settings.Properties["video"]->Statistics["width"];
	video_height = settings.Properties["video"]->Statistics["height"];
	vsync = (bool)settings.Statistics["vsync"]; // Not Implemented Yet
	frame_limit = settings.Statistics["frame_limit"];
	window_title = settings.Dictionary["window_title"];

	auto video_mode = sf::VideoMode(video_width, video_height);
	this->_window = new sf::RenderWindow(video_mode, window_title);
	if(frame_limit) this->_window->setFramerateLimit(frame_limit);
}

void SrpgEngine::S2dge::Simple2DGraphicsEngine::Update()
{
	this->_window->clear(sf::Color::Black);
	sf::Event event;
	while (_window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			_window->close();
		// Notify that the window closed;
	}

	//sf::RectangleShape sp;
	_window->clear(sf::Color::Black);
	for(auto pair : this->GameObjects)
	{
		Game::GameObject *obj = pair.second;
		sf::Sprite *sp = (sf::Sprite*)obj->Properties["sprite"]->Data["sprite"];

		//Physics System?
		int cx = obj->Properties["position"]->Statistics["x"];
		int cy = obj->Properties["position"]->Statistics["y"];
		auto dx = obj->Properties["destination"]->Statistics["x"];
		auto dy = obj->Properties["destination"]->Statistics["y"];
		int sx = obj->Properties["speed"]->Statistics["x"];
		int sy = obj->Properties["speed"]->Statistics["y"];
		obj->Properties["position"]->Statistics["x"] = cx < dx ? cx + sx : cx;
		obj->Properties["position"]->Statistics["y"] = cy < dy ? cy + sy : cy;
		//

		//Animation system?
		sp->setColor(sf::Color((unsigned)obj->Statistics["argb"]));
		sp->setTextureRect(sf::IntRect(0,0,32,32));
		sp->setPosition(obj->Properties["position"]->Statistics["x"],obj->Properties["position"]->Statistics["y"]);
		//sp->setScale(sf::Vector2f(obj->Statistics["width"],obj->Statistics["height"]));

		//
		_window->draw(*sp);
	}
	this->_window->display();
}

SrpgEngine::Framework::string SrpgEngine::S2dge::Simple2DGraphicsEngine::GetSystemCode()
{
	return S2dge::SystemName;
}

SrpgEngine::S2dge::Simple2DGraphicsEngine::~Simple2DGraphicsEngine()
{
	delete this->_window;
}
