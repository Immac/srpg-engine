#include "tile-position-system.hpp"

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

void TilePositionSystem::Initialize(GameObject &settings)
{
	auto item = this->GameObjects["Cursor"]
				->Properties["TILEPOS"];
	this->_eventMap["Right"] = [=](GameObject *event){
		item->Statistics["x"]++;
	};
	this->_eventMap["Left"] = [=](GameObject *event){
		item->Statistics["x"]--;
	};
	this->_eventMap["Up"] = [=](GameObject *event){
		item->Statistics["y"]--;
	};
	this->_eventMap["Down"] = [=](GameObject *event){
		item->Statistics["y"]++;
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

