#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>
#include <algorithm>


using namespace SrpgEngine::Framework::Lua;
using namespace SrpgEngine;
using namespace SrpgEngine::Framework;
using SrpgEngine::S2dge::Simple2DGraphicsEngine;
using SrpgEngine::Game::GameObject;

using std::cout;

string Simple2DGraphicsEngine::SystemName = "S2DGE";

Vector<GameObject *> Simple2DGraphicsEngine::getDrawables() const
{
	return _drawables;
}

void Simple2DGraphicsEngine::InitializeDefaults(GameObject &settings)
{
	for(auto pair : this->GameObjects)
	{
		GameObject *game_object = pair.second;
		game_object->Systems.insert(this->GetSystemCode());
		auto s2dge = game_object->Properties["S2DGE"];
		auto InitializeDefault = [&](string key, auto value)
		{
			if(!s2dge->Statistics.Exists(key)) { s2dge->Statistics[key] = value; }
		};
		InitializeDefault("x",0);
		InitializeDefault("y",0);
		InitializeDefault("x-offset",0);
		InitializeDefault("y-offset",0);
		InitializeDefault("red",255);
		InitializeDefault("green",255);
		InitializeDefault("blue",255);
		InitializeDefault("alpha",255);
		InitializeDefault("width",64);
		InitializeDefault("heigth",64);
	}
}

Simple2DGraphicsEngine::Simple2DGraphicsEngine()
{
	this->_eventMap["UpdateLayers"] = [&](){
		this->_drawables = SrpgEngine::Util::ExtractValues(this->GameObjects);
		std::sort(_drawables.begin()
				  ,_drawables.end()
				  ,[](GameObject *a, GameObject *b) {
			return a->Properties["S2DGE"]->Statistics["z"]
					< b->Properties["S2DGE"]->Statistics["z"];
		});
	};
}

void Simple2DGraphicsEngine::Initialize(GameObject &settings)
{
	this->InitializeDefaults(settings);
	for(auto game_object : this->GameObjects)
	{
		GameObject *object = game_object.second;

		auto sprite_game_object = new GameObject();
		auto s2dge = object->Properties["S2DGE"];



		s2dge->Properties["sprite"] = sprite_game_object;
		sprite_game_object->Name = "sprite";
		sprite_game_object->Statistics["widht"] = object->Statistics["width"];
		sprite_game_object->Statistics["height"] = object->Statistics["height"];

		sf::Sprite *sprite = new sf::Sprite();
		sf::Texture *texture = new sf::Texture();
		string texture_path = s2dge->Dictionary["texture"];

		if(!texture->loadFromFile(texture_path))
		{
			cout << "Texture not found at: \"" << texture_path;
			throw;
		}

		sprite->setTexture(*texture);
		s2dge->Properties["sprite"]->Data["sprite"] = sprite;
		s2dge->Properties["sprite"]->Data["texture"] = texture;
	}

	this->HandleEvent("UpdateLayers");

return;
}

void Simple2DGraphicsEngine::Update()
{

}

int Simple2DGraphicsEngine::HandleEvent(string eventKey)
{
	if(_eventMap.find(eventKey)!=_eventMap.end()){
		_eventMap[eventKey]();
	}
}

SrpgEngine::Framework::string SrpgEngine::S2dge::Simple2DGraphicsEngine::GetSystemCode()
{
	return SystemName;
}

Vector<SrpgEngine::Framework::string> Simple2DGraphicsEngine::GetDependencies()
{
	return Vector<string>();
}

SrpgEngine::S2dge::Simple2DGraphicsEngine::~Simple2DGraphicsEngine()
{

}
