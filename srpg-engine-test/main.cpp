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
#include <simple-sound-system.hpp>
#include <functional>
#include <menu-system.hpp>
#include "event-handler.hpp"
#include "srpg-demo.hpp"

using namespace SrpgEngine;
using namespace S2dge;
using namespace SimplePositionSystem;
using namespace Game;
using namespace TileMovementSystem;
using namespace Audio;
using namespace SrpgDemo::Util;
using namespace SimpleMenuSystem;

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

	ConfigurationManager configuration_manager;

	auto s2dge_settings = configuration_manager.LoadConfigurationFor("S2DGE");
	auto video_width = s2dge_settings->Properties["Video"]->Statistics["width"];
	auto video_height = s2dge_settings->Properties["Video"]->Statistics["height"];
	auto vsync = static_cast<bool>(s2dge_settings->Statistics["vsync"]);
	auto frame_limit = s2dge_settings->Statistics["frame_limit"];
	auto window_title = s2dge_settings->Dictionary["window_title"];
	auto step_update_time_in_ms = s2dge_settings->Statistics["step_update_time_in_ms"];

	Synchronizer synchronizer(sf::milliseconds(step_update_time_in_ms));
	sf::VideoMode video_mode(video_width, video_height);
	sf::RenderWindow window(video_mode, window_title);
	window.setVerticalSyncEnabled(vsync);

	auto drawing_system =
			static_cast<Simple2DGraphicsEngine*>(core.Systems["S2DGE"]);
	synchronizer.Reset();
	EventHandler event_handler(core,window);
	while(window.isOpen()) {
		auto event = sf::Event();
		while (window.pollEvent(event)) {
			event_handler.Handle(event);
		}

		while(synchronizer.TryStep()) {
			core.Update();
			synchronizer.FinishStep();
		}

		window.clear(sf::Color::Blue);

		for(const auto &object : drawing_system->getDrawables()) {
			auto& sprite =
					*static_cast<sf::Sprite *>(object->Data["graphic"]);
			window.draw(sprite);
		}
		window.display();
	}
	return 0;
}

Core setup_core() {
	Core core;

	auto s2dge = new Simple2DGraphicsEngine(&core);
	auto sts = new TilePositionSystem(&core);
	auto sss = new SimpleSoundSystem(core);
	auto menu = new MenuSystem(core);


	core.Systems[s2dge->GetSystemCode()] = s2dge;
	core.Systems[sts->GetSystemCode()] = sts;
	core.Systems[sss->GetSystemCode()] = sss;
	core.Systems[menu->GetSystemCode()] = menu;

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
