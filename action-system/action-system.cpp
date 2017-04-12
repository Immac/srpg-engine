#include "action-system.hpp"

using namespace SrpgEngine::ActionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

void SimpleActionSystem::Initialize(GameObject &settings)
{

}

void SimpleActionSystem::Update()
{
	//auto actionQ = this->GameObjects["ActionQueue"];

}

string SimpleActionSystem::GetSystemCode()
{
	return "SAS";
}
