#ifndef SRPG_GAME_SETTINGS_HPP
#define SRPG_GAME_SETTINGS_HPP
#include "gameobject.hpp"
#include "luautil.hpp"
#include "sol.hpp"
#include "algorithm"
#include <exception>

namespace SrpgEngine {
namespace Game {

using SrpgEngine::Framework::Lua::LuaGameObjectFactory;

class ConfigurationManager {
private:
	string _config_filepath = "game.config";
public:
	GameObject *LoadConfigurationFor(string system) {
		const string key = system + ".Config";
		sol::state config_state;
		config_state.open_libraries(sol::lib::base, sol::lib::package);
		config_state.script_file(_config_filepath);
		LuaGameObjectFactory luaGameObjectFactory(&config_state);
		auto config_objects = luaGameObjectFactory.CreateList();
		GameObject *dummy = new GameObject();
		dummy->Name = key;
		try{
			auto game_object_iterator = std::find_if(config_objects.begin(),config_objects.end(),[&key](const GameObject *o){return key == o->Name;});
			auto was_found = game_object_iterator != config_objects.end();
			if(!was_found)
			{
				throw "game_object was not found" // TODO: specify which one was not found
			}
			GameObject *config = new GameObject();
			config->Properties["video"] = new GameObject();
			config->Properties["video"]->Statistics["width"] = config_state[system]["width"];
			config->Properties["video"]->Statistics["height"] = config_state[system]["height"];
			config->Statistics["vsync"] = config_state[system]["vsync"]; // Not Implemented Yet
			config->Statistics["frame_limit"] = config_state[system]["frame_limit"];
			config->Dictionary["window_title"] = config_state[system]["window_title"];
			delete dummy;
			return config;
		}
		catch(std::exception e)
		{
			std::cout << e.what() << std::endl;
			delete dummy;
			throw;
		}
	}
};
}
}

#endif // SRPG_GAME_SETTINGS_HPP
