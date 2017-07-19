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
	for(const auto& systemPair : this->Systems) {
		auto system = systemPair.second;
		for(auto record : this->Objects) {
			auto systems = record.second->Systems;
			const auto& system_code = system->GetSystemCode();
			auto dependencies = system->GetDependencies();

			if(Util::HasAny(systems , system_code)) {
				system->GameObjects.insert(record);
			} else {
				if(dependencies.size() > 0) {
					bool hasAllDependencies = true;
					for(const auto &dependency : dependencies) {
						bool hasDependency = Util::HasAny(systems, dependency);
						hasAllDependencies = hasAllDependencies && hasDependency;
						if(!hasAllDependencies) break;
					}
					if(hasAllDependencies) {
						system->GameObjects.insert(record);
					}
				}
			}
		}
	}
}

void Core::LoadCoreObjects()
{
	auto config = configuration_manage_.LoadConfigurationFor("Core");
	const string &object_database_file_path = config->Dictionary["game_object_database_filepath"];
	sol::state game_objects_state;
	game_objects_state.open_libraries(sol::lib::base, sol::lib::package);
	game_objects_state.script_file(object_database_file_path);
	LuaGameObjectFactory factory(&game_objects_state);
	auto objects = factory.CreateList();
	for(const auto &game_object : objects)
	{
		this->Objects[game_object->Name] = game_object;
	}
}

Core::Core()
{
	for(int i = 0; i < controller_count_ ; i++)
	{
		this->Controllers.emplace(i,new GameController());
	}

	this->game_state_.CreateState("global");
	this->game_state_["global"]["input_pressed"]
			= [this](auto event)
	{
		const auto& input_key = event.Dictionary["input"];
		const auto& controller_index = event.Statistics["controller"];
		const auto& controller = this->Controllers[controller_index];
		controller->DigitalInputs[input_key] = true;
	};

	this->game_state_["global"]["input_released"]
			= [this](auto event)
	{
		const auto& input_key = event.Dictionary["input"];
		const auto& controller_index = event.Statistics["controller"];
		const auto& controller = this->Controllers[controller_index];
		controller->DigitalInputs[input_key] = false;
	};

}

void Core::HandleEvent(GameObject &event)
{
	if(event.Properties.HasAny(event.Name)){
		std::cout << "listener"	 <<std::endl;
	}
	game_state_.HandleEvent(event);
	game_state_["global"].HandleEvent(event);

	for(const auto& record: this->Systems)
	{
		auto system = record.second;
		system->HandleEvent(event);
	}
}

void Core::Init()
{
	LoadCoreObjects();
	LoadSystemObjects();

	for(const auto& systemPair : this->Systems)
	{
		const auto& system = systemPair.second;
		auto& settings = *configuration_manage_.LoadConfigurationFor(system->GetSystemCode());
		system->Initialize(settings);
	}
}

void SrpgEngine::Game::Core::Update()
{
	for(const auto& system : this->Systems)
	{
		system.second->Update();
	}
}
