#include "tile-position-system.hpp"

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

void TilePositionSystem::Initialize(GameObject &settings)
{
	auto item = this->GameObjects["Cursor"]
				->Properties["TILEPOS"];
	this->_eventMap["Right"] = [=](){
		item->Statistics["x"]++;
	};
	this->_eventMap["Left"] = [=](){
		item->Statistics["x"]--;
	};
	this->_eventMap["Up"] = [=](){
		item->Statistics["y"]--;
	};
	this->_eventMap["Down"] = [=](){
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

int TilePositionSystem::HandleEvent(string eventKey)
{
	if(_eventMap.find(eventKey)!=_eventMap.end()){
		_eventMap[eventKey]();
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

