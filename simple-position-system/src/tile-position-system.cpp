#include "tile-position-system.hpp"

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

TilePositionSystem::TilePositionSystem()
{

}

void TilePositionSystem::Initialize(GameObject &settings)
{

	this->_eventMap["MoveCursor"] = [=](GameObject *event){
		string subject_key = event->Dictionary["Subject"];
		string stat_key = event->Dictionary["Statistic"];
		int magnitude = event->Statistics["Magnitude"];
		GameObject *subject = this->GameObjects[subject_key];
		subject->Properties["TILEPOS"]->Statistics[stat_key]
				= subject->Properties["TILEPOS"]->Statistics[stat_key]
				  + magnitude;
	};
}

void TilePositionSystem::Update()
{

	for(auto item : this->GameObjects)
	{
		auto a = item.first;
		auto b = item.second;
		auto c = 1;
	}
}

int TilePositionSystem::HandleEvent(GameObject *event)
{

	string eventKey = event->Name;
	if(_eventMap.find(eventKey)!=_eventMap.end()){
		_eventMap[eventKey](event);
	}
}

string TilePositionSystem::GetSystemCode()
{
	return "TILEPOS";
}

Vector<string> TilePositionSystem::GetDependencies()
{
	return Vector<string>();
}

