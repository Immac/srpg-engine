#include "action-system.hpp"

using namespace SrpgEngine::ActionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

void SimpleActionSystem::Initialize(GameObject &settings)
{
	context_.CreateState("global")
			.CreateState("idle");

}

void SimpleActionSystem::Update()
{
}

string SimpleActionSystem::GetSystemCode()
{
	return "SAS";
}
 

Vector<string> SrpgEngine::ActionSystem::SimpleActionSystem::GetDependencies()
{
	return Vector<string> {
		"TILEPOS"
	};
}

int SrpgEngine::ActionSystem::SimpleActionSystem::HandleEvent(GameObject& event)
{
	return 0;
}
