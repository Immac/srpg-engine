#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-gamesystem.hpp>
#include <tile-position-system.hpp>
#include <s2dge-tilepos-adapter.hpp>
#include <configuration-manager.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include "chess.hpp"

using namespace SrpgEngine::S2dge;
using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Game;
using SrpgEngine::Framework::string;
#define SANDBOX 0

Core setupCore();
inline void sandbox();

int main(){
	sandbox();

	if(SANDBOX) return 0;

	Core core = setupCore();

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


	Simple2DGraphicsEngine *drawingSystem = (Simple2DGraphicsEngine*)core.SystemMap["S2DGE"];
	bool firstRun = true;
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
				case sf::Keyboard::L:
					{
						core.HandleEvent("UpdateLayers");
					}
					break;
				case sf::Keyboard::Escape:
					{
						window->close();
					}
					break;
				case sf::Keyboard::Right:
					{
						core.HandleEvent("Right");
					}
					break;
				case sf::Keyboard::Left:
					{
						core.HandleEvent("Left");
					}
					break;
				case sf::Keyboard::Up:
					{
						core.HandleEvent("Up");
					}
					break;
				case sf::Keyboard::Down:
					{
						core.HandleEvent("Down");
					}
					break;
				default:
					break;
				}
			}
		}
		core.Update();
		window->clear(sf::Color::Blue);
		Vector<GameObject *> drawables = drawingSystem->getDrawables();
		for(GameObject* obj : drawables)
		{
			auto s2dge = obj->Properties[drawingSystem->GetSystemCode()];
			sf::Sprite *sp = (sf::Sprite*)s2dge
							 ->Properties["sprite"]
							 ->Data["sprite"];

			uint8_t red = s2dge->Statistics["red"];
			uint8_t green = s2dge->Statistics["green"];
			uint8_t blue = s2dge->Statistics["blue"];
			uint8_t alpha = s2dge->Statistics["alpha"];
			sp->setColor(sf::Color(red,green,blue,alpha));
			sp->setPosition(s2dge->Statistics["x"] + s2dge->Statistics["x-offset"]
					, s2dge->Statistics["y"] + s2dge->Statistics["y-offset"]);
			window->draw(*sp);
		}

		window->display();
	}

	return 0;
}

bool Configure(){

}

Core setupCore()
{
	Core core;
	core.EventMap["hello"] = []() { std::cout << "Hello from a Lambda!" << std::endl; };

	auto s2dge = new Simple2DGraphicsEngine();
	auto sts = new TilePositionSystem();
	auto s2dge_sts = new S2dgeTilePosAdapter();

	core.SystemMap[s2dge->GetSystemCode()] = s2dge;
	core.SystemMap[sts->GetSystemCode()] = sts;
	core.SystemMap[s2dge_sts->GetSystemCode()] = s2dge_sts;

	auto factory = ChessExample::BoardFactory();
	auto board = factory.CreateBoard();
	for(GameObject* item : board)
	{
		string s = item->Name;
		core.ObjectMap[s] = item;
	}
	core.Init();
	return core;
}

#if SANDBOX
inline void sandbox(){
	std::function<bool()> f = [](){return true;};
	std::cout << (f() ? "True" : "False") << std::endl;
}

#else
inline void sandbox(){

}
#endif
