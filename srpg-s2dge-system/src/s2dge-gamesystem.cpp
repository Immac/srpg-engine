#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>

using namespace SrpgEngine::Framework::Lua;
using SrpgEngine::Framework::string;
using SrpgEngine::S2dge::Simple2DGraphicsEngine;
using SrpgEngine::Game::GameObject;

void Simple2DGraphicsEngine::Initialize(Game::GameObject &settings)
{
	int video_width, video_height, frame_limit;
	bool vsync;
	string window_title;

	video_width = settings.Properties["Video"]->Statistics["width"];
	video_height = settings.Properties["Video"]->Statistics["height"];
	vsync = (bool)settings.Statistics["vsync"]; // Not Implemented Yet
	frame_limit = settings.Statistics["frame_limit"];
	window_title = settings.Dictionary["window_title"];

	auto video_mode = sf::VideoMode(video_width, video_height);
	this->_window = new sf::RenderWindow(video_mode, window_title);
	if(frame_limit) this->_window->setFramerateLimit(frame_limit);

	for(auto game_object : this->GameObjects)
	{
		GameObject *object = game_object.second;
		object->Systems.insert(this->GetSystemCode());

		object->Properties["sprite"] = new GameObject();
		object->Properties["sprite"]->Name = "sprite";
		object->Properties["sprite"]->Statistics["widht"] = object->Statistics["width"];
		object->Properties["sprite"]->Statistics["height"] = object->Statistics["height"];

		sf::Sprite *sprite = new sf::Sprite();
		sf::Texture *texture = new sf::Texture();
		if(!texture->loadFromFile(object->Dictionary["texture"]))
			throw "Texture not found";

		sprite->setTexture(*texture);
		object->Properties["sprite"]->Data["sprite"] = sprite;
		object->Properties["sprite"]->Data["texture"] = texture;

	}
	return;
}

void Simple2DGraphicsEngine::Update()
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

	_window->clear(sf::Color::Black);
	for(auto pair : this->GameObjects)
	{
		GameObject *obj = pair.second;
		sf::Sprite *sp = (sf::Sprite*)obj->Properties["sprite"]->Data["sprite"];

//		//Physics System?
//		int cx = obj->Properties["position"]->Statistics["x"];
//		int cy = obj->Properties["position"]->Statistics["y"];
//		auto dx = obj->Properties["destination"]->Statistics["x"];
//		auto dy = obj->Properties["destination"]->Statistics["y"];
//		int sx = obj->Properties["speed"]->Statistics["x"];
//		int sy = obj->Properties["speed"]->Statistics["y"];
//		obj->Properties["position"]->Statistics["x"] = cx < dx ? cx + sx : cx;
//		obj->Properties["position"]->Statistics["y"] = cy < dy ? cy + sy : cy;
//		//
		uint8_t red = obj->Statistics["red"];
		uint8_t green = obj->Statistics["green"];
		uint8_t blue = obj->Statistics["blue"];
		uint8_t alpha = obj->Statistics["alpha"];

		//Animation system?
		sp->setColor(sf::Color(red,green,blue,alpha));
		//sp->setTextureRect(sf::IntRect(0,0,64,64));
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
