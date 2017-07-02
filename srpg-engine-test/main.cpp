#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-gamesystem.hpp>
#include <tile-position-system.hpp>
#include <s2dge-tilepos-adapter.hpp>
#include <configuration-manager.hpp>
#include <simple-tile-movement-system.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include "event-handler.hpp"

using namespace SrpgEngine::S2dge;
using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Game;
using namespace SrpgEngine::TileMovementSystem;
using SrpgEngine::Framework::string;
using CoreSp = std::shared_ptr<Core>;
using WindowSp = std::shared_ptr<sf::Window>;

#define SANDBOX 0

Core setupCore();
inline void sandbox();

int main(){
	sandbox();
	if(SANDBOX) return 0;

	Core core = setupCore();

	ConfigurationManager _configurationManager;

	auto s2dge_settings = _configurationManager.LoadConfigurationFor("S2DGE");
	int video_width, video_height, frame_limit, step_update_time_in_ms;
	bool vsync;

	sf::Time ms_per_frame;
	sf::Time lag = sf::Time::Zero;
	sf::Clock clock;
	string window_title;

	video_width = s2dge_settings->Properties["Video"]->Statistics["width"];
	video_height = s2dge_settings->Properties["Video"]->Statistics["height"];
	vsync = (bool)s2dge_settings->Statistics["vsync"];
	frame_limit = s2dge_settings->Statistics["frame_limit"];
	window_title = s2dge_settings->Dictionary["window_title"];
	step_update_time_in_ms = s2dge_settings->Statistics["step_update_time_in_ms"];
	ms_per_frame = sf::milliseconds(step_update_time_in_ms);

	auto video_mode = sf::VideoMode(video_width, video_height);
	sf::RenderWindow window(video_mode, window_title);
	window.setVerticalSyncEnabled(vsync);


	Simple2DGraphicsEngine *drawingSystem = (Simple2DGraphicsEngine*)core.SystemMap["S2DGE"];
	clock.restart();

	EventHandler event_handler(core,window);
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			event_handler.Handle(event);
		}

		lag += clock.getElapsedTime();
		while(lag >= ms_per_frame)
		{
			core.Update();
			lag -= ms_per_frame;
		}
		clock.restart();

		window.clear(sf::Color::Blue);
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
			window.draw(*sp);
		}
		window.display();
	}
	return 0;
}

Core setupCore()
{
	Core core;

	auto s2dge = new Simple2DGraphicsEngine();
	auto sts = new TilePositionSystem(&core);
	auto s2dge_sts = new S2dgeTilePosAdapter();
	auto stms = new TileMovementSystem();

	core.SystemMap[s2dge->GetSystemCode()] = s2dge;
	core.SystemMap[sts->GetSystemCode()] = sts;
	core.SystemMap[s2dge_sts->GetSystemCode()] = s2dge_sts;
	core.SystemMap[stms->GetSystemCode()] = stms;

	core.Init();
	return core;
}

#if SANDBOX
inline void sandbox(){
	std::cout << "Sandbox" << std::endl;
}

#else
inline void sandbox(){}
#endif
