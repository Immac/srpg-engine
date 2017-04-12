#include "simple-position-system.hpp"

using namespace SrpgEngine::ActionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

void SimplePositionSystem::Initialize(GameObject &settings)
{

}

void SimplePositionSystem::Update()
{
	//auto actionQ = this->GameObjects["ActionQueue"];

}

string SimplePositionSystem::GetSystemCode()
{
	return "SPS";
}
