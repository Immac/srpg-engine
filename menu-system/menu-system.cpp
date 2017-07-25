#include "menu-system.hpp"
using namespace SrpgEngine;
using namespace Framework;
using namespace Game;
using namespace SimpleMenuSystem;


MenuSystem::MenuSystem::MenuSystem(SrpgEngine::Game::Core& core)
	:core_(&core)
{

}

void MenuSystem::Initialize(GameObject& settings)
{

}

void MenuSystem::Update()
{
}

string MenuSystem::GetSystemCode()
{
	return "MENU";
}

Vector<string> MenuSystem::GetDependencies()
{
	return Vector<string>();
}

int MenuSystem::HandleEvent(GameObject& event)
{
	return 0;
}
