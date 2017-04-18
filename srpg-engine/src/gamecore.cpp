#include "gamecore.hpp"
#include "configuration-manager.hpp"

#include <iostream>
#include <string>

using namespace SrpgEngine;
using namespace Game;
using string = std::string;
using std::cout;
using std::cin;
using Game::Lua::LuaGameObjectFactory;

void Core::LoadSystemObjects()
{
	for(auto systemPair : this->SystemMap)
	{
		GameSystem *system = systemPair.second;
		for(auto object_pair : this->ObjectMap)
		{
			auto systems = object_pair.second->Systems;
			if(Util::Find(systems ,system->GetSystemCode()))
				system->GameObjects.insert(object_pair);
		}
	}
}

void Core::LoadCoreObjects()
{
	auto config = _configurationManager.LoadConfigurationFor("Core");
	string object_database_file_path = config->Dictionary["game_object_database_filepath"];
	sol::state game_objects_state;
	game_objects_state.open_libraries(sol::lib::base,sol::lib::package);
	game_objects_state.script_file(object_database_file_path);
	LuaGameObjectFactory f(&game_objects_state);
	auto objects = f.CreateList();
	for(GameObject *g : objects)
	{
		this->ObjectMap[g->Name] = g;
	}
}

Core::Core()
{

}

int Core::HandleEvent(string eventName)
{
	EventMap[eventName]();
}

int Core::Init()
{
	// Initialize Core Objects
	this->_status = Status::Initializing;
	LoadCoreObjects();
	LoadSystemObjects();
	//TODO initialize settings

	for(auto systemPair : this->SystemMap)
	{
		auto system = systemPair.second;
		GameObject *settings = _configurationManager.LoadConfigurationFor(system->GetSystemCode());
		system->Initialize(*settings);
	}
	this->_status = Status::Running;
}

int SrpgEngine::Game::Core::Update()
{
	this->_status = Status::Running;

	for(auto system : this->SystemMap)
	{
		system.second->Update();
	}

	return 0;
}
