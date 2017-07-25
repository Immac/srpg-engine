#include "configuration-manager.hpp"

using SrpgEngine::Game::ConfigurationManager;
using SrpgEngine::Framework::string;

const string ConfigurationManager::DefaultConfigIdTag = ".Config";
const string ConfigurationManager::DefaultFilePath = "game.lua";
const string ConfigurationManager::ConfigurationNotFoundMessage =
		"game.config";

ConfigurationManager::ConfigurationManager()
	: ConfigurationManager(DefaultFilePath,DefaultConfigIdTag)
{
}

ConfigurationManager::ConfigurationManager(const SrpgEngine::Framework::string configFilePath)
	:ConfigurationManager(configFilePath,DefaultConfigIdTag)
{
}

ConfigurationManager::ConfigurationManager(const SrpgEngine::Framework::string configFilePath, const SrpgEngine::Framework::string configIdTag)
	:_filepath(configFilePath), _id_tag(configIdTag)
{
}

SrpgEngine::Game::GameObject *ConfigurationManager::LoadConfigurationFor(SrpgEngine::Framework::string system) {
	const string key = system + _id_tag;
	sol::state config_state;
	config_state.open_libraries(sol::lib::base, sol::lib::package);
	config_state.script_file(_filepath);
	LuaGameObjectFactory luaGameObjectFactory(&config_state);
	auto config_objects = luaGameObjectFactory.CreateList();
	try{
		auto game_object_iterator =
				std::find_if(
					config_objects.begin(),
					config_objects.end(),
					[&key](const GameObject *o){return key == o->Name;});
		auto was_found = game_object_iterator != config_objects.end();
		if(!was_found)
		{
			std::cout << "The object: " << key << " was not found" << std::endl;//TODO: Exception
			throw std::runtime_error(std::string("game_object was not found: ") + key); // TODO: specify which one was not found
		}
		GameObject *config = *game_object_iterator;
		return config;
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return nullptr;
}
