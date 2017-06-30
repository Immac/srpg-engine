#include "s2dge-tilepos-adapter.hpp"
#include <algorithm>

using namespace SrpgEngine;
using namespace SrpgEngine::Framework;
using namespace SimplePositionSystem;


S2dgeTilePosAdapter::S2dgeTilePosAdapter()
	: _systemName("S2DGE-TILEPOS")
{
	this->_dependencies.push_back("TILEPOS");
}

void S2dgeTilePosAdapter::Initialize(GameObject &settings)
{
	this->_tileSize = 64; //TODO: get from settings
}

void S2dgeTilePosAdapter::Update()
{
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
