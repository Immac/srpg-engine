#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>

using namespace SrpgEngine::Framework::Lua;
using SrpgEngine::Framework::string;
using SrpgEngine::S2dge::Simple2DGraphicsEngine;
using SrpgEngine::Game::GameObject;

void Simple2DGraphicsEngine::Initialize(Game::GameObject &settings)
{
	for(auto game_object : this->GameObjects)
	{
		GameObject *object = game_object.second;
		object->Systems.insert(this->GetSystemCode());

		object->Properties["sprite"] = new GameObject();
		object->Properties["sprite"]->Name = "sprite";
		object->Properties["sprite"]->Statistics["widht"] = object->Statistics["width"];
		object->Properties["sprite"]->Statistics["height"] = object->Statistics["height"];

		sf::Sprite *sprite = new sf::Sprite();
		sf::Texture *texture = new sf::Texture();
		if(!texture->loadFromFile(object->Dictionary["texture"]))
			throw "Texture not found";

		sprite->setTexture(*texture);
		object->Properties["sprite"]->Data["sprite"] = sprite;
		object->Properties["sprite"]->Data["texture"] = texture;

	}
	return;
}

void Simple2DGraphicsEngine::Update()
{

}

SrpgEngine::Framework::string SrpgEngine::S2dge::Simple2DGraphicsEngine::GetSystemCode()
{
	return S2dge::SystemName;
}

SrpgEngine::S2dge::Simple2DGraphicsEngine::~Simple2DGraphicsEngine()
{

}
