#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>

using namespace SrpgEngine::Framework::Lua;
using SrpgEngine::Framework::string;
using SrpgEngine::S2dge::Simple2DGraphicsEngine;
using SrpgEngine::Game::GameObject;
using std::cout;

string Simple2DGraphicsEngine::SystemName = "S2DGE";

void Simple2DGraphicsEngine::Initialize(Game::GameObject &settings)
{
	for(auto game_object : this->GameObjects)
	{
		GameObject *object = game_object.second;
		object->Systems.insert(this->GetSystemCode());
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
	return;
}

void Simple2DGraphicsEngine::Update()
{

}

SrpgEngine::Framework::string SrpgEngine::S2dge::Simple2DGraphicsEngine::GetSystemCode()
{
	return SystemName;
}

SrpgEngine::S2dge::Simple2DGraphicsEngine::~Simple2DGraphicsEngine()
{

}
