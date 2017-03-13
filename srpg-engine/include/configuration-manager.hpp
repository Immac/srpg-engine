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
	static const string DefaultFilePath;
	static const string DefaultConfigIdTag;
	string _filepath;
	string _id_tag;
public:
	ConfigurationManager();

	ConfigurationManager(const string configFilePath);

	ConfigurationManager(const string configFilePath,const string configIdTag);

	GameObject *LoadConfigurationFor(string system);
};
}
}

#endif // SRPG_GAME_SETTINGS_HPP
