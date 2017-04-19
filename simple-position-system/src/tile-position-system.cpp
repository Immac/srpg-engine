#include "simple-position-system.hpp"

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

void TilePositionSystem::Initialize(GameObject &settings)
{

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

string TilePositionSystem::GetSystemCode()
{
	return "TILEPOS";
}
