#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-factory.hpp>
#include <s2dge-gamesystem.hpp>
#include <configuration-manager.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace SrpgEngine::S2dge;
using namespace SrpgEngine::Game;
using SrpgEngine::Framework::string;
#define SANDBOX 0

void sandbox(){
	std::function<bool()> f = [](){return true;};
	std::cout << (f() ? "True" : "False") << std::endl;
}

int main(){
#if SANDBOX
		sandbox();
		return 0;
#endif
	Core core;
	core.SystemMap["S2DGE"] = new SrpgEngine::S2dge::Simple2DGraphicsEngine();

	ConfigurationManager _configurationManager;

	auto s2dge_settings = _configurationManager.LoadConfigurationFor("S2DGE");
	int video_width, video_height, frame_limit;
	bool vsync;
	string window_title;

	video_width = s2dge_settings->Properties["Video"]->Statistics["width"];
	video_height = s2dge_settings->Properties["Video"]->Statistics["height"];
	vsync = (bool)s2dge_settings->Statistics["vsync"];
	frame_limit = s2dge_settings->Statistics["frame_limit"];
	window_title = s2dge_settings->Dictionary["window_title"];

	auto video_mode = sf::VideoMode(video_width, video_height);
	auto window = new sf::RenderWindow(video_mode,window_title);
	window->setVerticalSyncEnabled(vsync);
	core.Init();

	GameSystem *drawingSystem = core.SystemMap["S2DGE"];

	while(window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window->close();
//			if (event.type == sf::Event::KeyPressed)
//				core.HandleEvent(new srpg::SfmlEvent(event));
			// Notify that the window closed;
		}
		window->clear(sf::Color::Black);
		for(auto pair : drawingSystem->GameObjects)
		{
			GameObject *obj = pair.second;
			sf::Sprite *sp = (sf::Sprite*)obj->Properties["sprite"]->Data["sprite"];

			uint8_t red = obj->Statistics["red"];
			uint8_t green = obj->Statistics["green"];
			uint8_t blue = obj->Statistics["blue"];
			uint8_t alpha = obj->Statistics["alpha"];
			sp->setColor(sf::Color(red,green,blue,alpha));
			sp->setPosition(obj->Properties["position"]->Statistics["x"],obj->Properties["position"]->Statistics["y"]);
			window->draw(*sp);
		}

		window->display();
	}

	return 0;
}

bool Configure(){

}
