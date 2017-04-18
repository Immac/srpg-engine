#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-gamesystem.hpp>
#include <simple-position-system.hpp>
#include <configuration-manager.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

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
	int num = 0;
	core.EventMap["hello"] = [&num]() {
		num++;
		std::cout << "Hello from a Lambda: " << num << std::endl;
		return;
	};
	core.SystemMap["S2DGE"] = new SrpgEngine::S2dge::Simple2DGraphicsEngine();
	core.SystemMap["SPS"] = new SrpgEngine::SimplePositionSystem::TilePositionSystem;
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
			if(event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code) {
				case sf::Keyboard::H:
					{
						core.HandleEvent("hello");
					}
					break;
				case sf::Keyboard::Escape:
					{
						window->close();
					}
					break;
				default:
					break;
				}
			}
		}
		core.Update();
		window->clear(sf::Color::Black);
		for(auto pair : drawingSystem->GameObjects)
		{
			GameObject *obj = pair.second;
			auto s2dge = obj->Properties["S2DGE"];
			sf::Sprite *sp = (sf::Sprite*)s2dge
							 ->Properties["sprite"]
							 ->Data["sprite"];

			uint8_t red = s2dge->Statistics["red"];
			uint8_t green = s2dge->Statistics["green"];
			uint8_t blue = s2dge->Statistics["blue"];
			uint8_t alpha = s2dge->Statistics["alpha"];
			sp->setColor(sf::Color(red,green,blue,alpha));
			sp->setPosition(s2dge->Statistics["x"],s2dge->Statistics["y"]);
			window->draw(*sp);
		}

		window->display();
	}

	return 0;
}

bool Configure(){

}
