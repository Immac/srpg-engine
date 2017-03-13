#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-factory.hpp>
#include <s2dge-gamesystem.hpp>
#include <configuration-manager.hpp>

using namespace SrpgEngine::S2dge;
using SrpgEngine::Game::ConfigurationManager;
using SrpgEngine::Framework::string;
using SrpgEngine::Game::Core;

int main(){

	Core core;

	// Load Core Objects

	//
//	DrawableTestObjectFactory factory;
//	auto item = factory.Create();
//	auto item2 = factory.Create();
//	auto item3 = factory.Create();

	auto s2dge = new Simple2DGraphicsEngine(); //TODO: make configurable

//	core.Objects["1"] = &item;
//	core.Objects["2"] = &item2;
//	core.Objects["3"] = &item3;

	core.SystemMap[s2dge->GetSystemCode()] = s2dge;

	core.Init();
	core.Run();
	return 0;
}
