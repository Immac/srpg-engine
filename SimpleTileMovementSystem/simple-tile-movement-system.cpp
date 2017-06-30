#include "simple-tile-movement-system.hpp"

using namespace SrpgEngine;
using namespace Framework;
using namespace Game;


TileMovementSystem::TileMovementSystem::TileMovementSystem()
{
	this->_dependencies = Vector<string> {"TILEPOS"};
}

void TileMovementSystem::TileMovementSystem::Initialize(GameObject &settings)
{
}

void TileMovementSystem::TileMovementSystem::Update()
{
}

int TileMovementSystem::TileMovementSystem::HandleEvent(GameObject *event)
{

}

string TileMovementSystem::TileMovementSystem::GetSystemCode()
{
	return "STMS";
}

Vector<string> TileMovementSystem::TileMovementSystem::GetDependencies()
{
	return this->_dependencies;
}
