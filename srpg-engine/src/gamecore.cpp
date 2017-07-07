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
	for(auto systemPair : this->SystemMap) {
		auto system = systemPair.second;
		for(auto object_pair : this->ObjectMap) {
			auto systems = object_pair.second->Systems;
			auto system_code = system->GetSystemCode();
			auto dependencies = system->GetDependencies();

			if(Util::HasAny(systems , system_code)) {
				system->GameObjects.insert(object_pair);
			} else {
				if(dependencies.size() > 0) {
					bool hasAllDependencies = true;
					for(const auto &dependency : dependencies) {
						bool hasDependency = Util::HasAny(systems, dependency);
						hasAllDependencies = hasAllDependencies && hasDependency;
						if(!hasAllDependencies) break;
					}
					if(hasAllDependencies) {
						system->GameObjects.insert(object_pair);
					}
				}
			}
		}
	}
}

void Core::LoadCoreObjects()
{
	auto config = _configurationManager.LoadConfigurationFor("Core");
	const string &object_database_file_path = config->Dictionary["game_object_database_filepath"];
	sol::state game_objects_state;
	game_objects_state.open_libraries(sol::lib::base,sol::lib::package);
	game_objects_state.script_file(object_database_file_path);
	LuaGameObjectFactory factory(&game_objects_state);
	auto objects = factory.CreateList();
	for(const auto &g : objects)
	{
		this->ObjectMap[g->Name] = g;
	}
}

Core::Core()
{
	for(int i = 0; i < this->_controller_count ; i++)
	{
		this->Controllers.emplace(i,new GameController());
	}
}

int Core::HandleEvent(GameObject *event)
{
	string eventName = event->Name;
	if(EventMap.find(eventName)!=EventMap.end()){
		EventMap[eventName](event);
	}

	for(const auto& mapPair: this->SystemMap)
	{
		GameSystem *system = mapPair.second;
		system->HandleEvent(event);
	}
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
