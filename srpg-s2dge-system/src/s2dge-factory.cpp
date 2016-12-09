#include "s2dge-factory.hpp"
using namespace SrpgEngine;

SrpgEngine::Game::GameObject SrpgEngine::S2dge::DrawableTestObjectFactory::Create()
{
	Game::GameObject object;
	object.Name = "test";
	object.Statistics["height"] = 100;
	object.Statistics["width"] = 100;
	object.Statistics["argb"] = 0xfff00fff;
	object.Statistics["textured"] = false;

	//
	auto property = new Game::GameObject();
	property->Name = "destination";
	property->Statistics["x"] = 200;
	property->Statistics["y"] = 300;
	object.Properties["destination"] = property;
	//
	property = new Game::GameObject();
	property->Name = "position";
	property->Statistics["x"] = 10;
	property->Statistics["y"] = 20;
	object.Properties["position"] = property;
	//
	property = new Game::GameObject();
	property->Name = "speed";
	property->Statistics["x"] = 2;
	property->Statistics["y"] = 5;
	object.Properties["speed"] = property;
	//
	object.Tags.push_back("S2DGE");

	object.Dictionary.Add("texture","none");
	if(!Util::Find<Framework::string>(object.Systems,"S2DGE")) {
		object.Systems.insert("S2DGE");
	}
	return object;
}
