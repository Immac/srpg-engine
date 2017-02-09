#include "gamecore.hpp"
#include "configuration-manager.hpp"

#include <iostream>
#include <string>

using string = std::string;
using std::cout;
using std::cin;

int SrpgEngine::Game::Core::Init()
{
	this->_status = Status::Initializing;
	for(auto systemPair : this->Systems)
	{
		GameSystem *system = systemPair.second;
		for(auto object_pair : this->Objects)
		{
			auto systems = object_pair.second->Systems;
			if(Util::Find(systems ,system->GetSystemCode()))
				system->GameObjects.insert(object_pair);
		}
	}
	//TODO initialize settings
	ConfigurationManager cm;

	for(auto systemPair : this->Systems)
	{
		auto system = systemPair.second;
		auto settings = cm.LoadConfigurationFor(system->GetSystemCode());
		system->Initialize(settings);
	}
	this->_status = Status::Running;
}

int SrpgEngine::Game::Core::Run()
{
	this->_status = Status::Running;

	while(this->_status != Status::Stopped)
	{
		for(auto system : this->Systems)
		{
			system.second->Update();
		}
	}
	cout << "Good Bye" << std::endl;
	return 0;
}
