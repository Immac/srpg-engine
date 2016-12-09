#include "gamecore.hpp"

#include <iostream>
#include <string>

using string = std::string;
using std::cout;
using std::cin;
int SrpgEngine::Game::Core::Run()
{
	this->_status = Status::Running;

	while(this->_status != Status::Stopped)
	{
		for(auto system : this->Systems)
		{
			system.second->Update({Objects.at("item")});
		}
	}
	cout << "Good Bye" << std::endl;
	return 0;
}
