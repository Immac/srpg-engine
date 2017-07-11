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
#include "srpg-demo.hpp"

using namespace SrpgEngine::S2dge;
using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Game;
using namespace SrpgEngine::TileMovementSystem;
using namespace SrpgDemo::Util;

using SrpgEngine::Framework::string;
using CoreSp = std::shared_ptr<Core>;
using WindowSp = std::shared_ptr<sf::Window>;
#define SANDBOX 0

Core setup_core();
inline void sandbox();

int main() {
	sandbox();
	if(SANDBOX) return 0;

	Core core = setup_core();

	ConfigurationManager _configurationManager;

	auto s2dge_settings = _configurationManager.LoadConfigurationFor("S2DGE");
	int video_width, video_height, frame_limit;
	bool vsync;

	video_width = s2dge_settings->Properties["Video"]->Statistics["width"];
	video_height = s2dge_settings->Properties["Video"]->Statistics["height"];
	vsync = static_cast<bool>(s2dge_settings->Statistics["vsync"]);
	frame_limit = s2dge_settings->Statistics["frame_limit"];
	auto window_title = s2dge_settings->Dictionary["window_title"];
	auto step_update_time_in_ms = s2dge_settings->Statistics["step_update_time_in_ms"];

	Synchronizer synchronizer(sf::milliseconds(step_update_time_in_ms));
	auto video_mode = sf::VideoMode(video_width, video_height);
	sf::RenderWindow window(video_mode, window_title);
	window.setVerticalSyncEnabled(vsync);

	auto drawing_system =
			static_cast<Simple2DGraphicsEngine*>(core.SystemMap["S2DGE"]);
	synchronizer.Reset();
	EventHandler event_handler(core,window);
	while(window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			event_handler.Handle(event);
		}

		while(synchronizer.TryStep()) {
			core.Update();
			synchronizer.FinishStep();
		}

		window.clear(sf::Color::Blue);

		for(const auto &object : drawing_system->getDrawables()) {
			const auto &sprite =
					static_cast<sf::Sprite *>(
						object->Properties[drawing_system->GetSystemCode()]
					->Properties["sprite"]->Data["sprite"]);
			window.draw(*sprite);
		}
		window.display();
	}
	return 0;
}

Core setup_core() {
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
