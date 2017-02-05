#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-factory.hpp>
#include <s2dge-gamesystem.hpp>


using namespace SrpgEngine::S2dge;
int main(){

	SrpgEngine::Game::Core core;

	DrawableTestObjectFactory factory;
	auto item = factory.Create();
	auto item2 = factory.Create();
	auto item3 = factory.Create();
	auto s2dge = new Simple2DGraphicsEngine();



	core.Objects["1"] = &item;
	core.Objects["2"] = &item2;
	core.Objects["3"] = &item3;

	core.Systems[s2dge->GetSystemCode()] = s2dge;

	core.Init();
	core.Run();
	return 0;
}
