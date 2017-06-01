#include "s2dge-tilepos-adapter.hpp"
#include <algorithm>

using namespace SrpgEngine;
using namespace SrpgEngine::Framework;
using namespace SimplePositionSystem;


S2dgeTilePosAdapter::S2dgeTilePosAdapter()
	: _systemName("S2DGE-TILEPOS")
{
	this->_dependencies.push_back("S2DGE");
	this->_dependencies.push_back("TILEPOS");
}

void S2dgeTilePosAdapter::Initialize(GameObject &settings)
{
	this->_tileSize = 64; //TODO: get from settings
}

void S2dgeTilePosAdapter::Update()
{
	for(auto pair : GameObjects){
		GameObject *item = pair.second;
		auto tilepos = item->Properties["TILEPOS"];
		auto s2dge = item->Properties["S2DGE"];
		s2dge->Statistics["x"] = tilepos->Statistics["x"] * this->_tileSize;
		s2dge->Statistics["y"] = tilepos->Statistics["y"] * this->_tileSize;
		s2dge->Statistics["x-offset"] = tilepos->Statistics["x-offset"];
		s2dge->Statistics["y-offset"] = tilepos->Statistics["y-offset"];
		s2dge->Statistics["z"] = tilepos->Statistics["z"];
	}
}

int S2dgeTilePosAdapter::HandleEvent(GameObject *event)
{
//TODO: Handle Events
}

string S2dgeTilePosAdapter::GetSystemCode()
{
	return this->_systemName;
}

Vector<string> S2dgeTilePosAdapter::GetDependencies()
{
	return this->_dependencies;
}
