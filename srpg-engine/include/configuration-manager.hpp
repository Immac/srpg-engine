#ifndef SRPG_GAME_SETTINGS_HPP
#define SRPG_GAME_SETTINGS_HPP
#include "gameobject.hpp"
#include "sol.hpp"

namespace SrpgEngine {
namespace Game {

class ConfigurationManager {
private:
	string _config_filepath = "game.config";
public:
	GameObject LoadConfigurationFor(string system) {
		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::package);
		lua.script_file(_config_filepath);

		GameObject config;
		config.Properties["video"] = new GameObject();
		config.Properties["video"]->Statistics["width"] = lua[system]["width"];
		config.Properties["video"]->Statistics["height"] = lua[system]["height"];
		config.Statistics["vsync"] = lua[system]["vsync"]; // Not Implemented Yet
		config.Statistics["frame_limit"] = lua[system]["frame_limit"];
		config.Dictionary["window_title"] = lua[system]["window_title"];
		return config;
	}
};
}
}

#endif // SRPG_GAME_SETTINGS_HPP
