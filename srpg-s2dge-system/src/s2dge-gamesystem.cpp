#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>
#include <algorithm>
#include <memory>

using namespace SrpgEngine;
using namespace Framework;
using namespace Lua;
using namespace Game;
using SrpgEngine::S2dge::Simple2DGraphicsEngine;

using std::cout;

string Simple2DGraphicsEngine::SystemName = "S2DGE";

Vector<GameObject *> Simple2DGraphicsEngine::getDrawables() const
{
	return _drawables;
}

void Simple2DGraphicsEngine::InitializeDefaults(GameObject &settings)
{
	const auto &system_code = this->GetSystemCode();
	for(auto record : this->GameObjects)
	{
		auto game_object = record.second;
		game_object->Systems.insert(system_code);
		auto s2dge = game_object->Properties[system_code];
		auto SetDefault = [&s2dge](string key, auto value)
		{
			if(!s2dge->Statistics.HasAny(key)) {
				s2dge->Statistics[key] = value;
			}
		};
		SetDefault("x",0);
		SetDefault("y",0);
		SetDefault("x-offset",0);
		SetDefault("y-offset",0);
		SetDefault("red",255);
		SetDefault("green",255);
		SetDefault("blue",255);
		SetDefault("alpha",255);
		SetDefault("width",64);
		SetDefault("heigth",64);
	}
}

Simple2DGraphicsEngine::Simple2DGraphicsEngine()
	:_system_states("normal")
{
	this->_system_states["normal"]["UpdateLayers"]=[this](auto e)
	{
		std::cout << "normal>nothing_selected";
	};

	this->_universal_events["UpdateLayers"] = [this](auto event)
	{
		this->_drawables = Util::ExtractValues(this->GameObjects);
		Util::Sort(_drawables,[](auto first, auto second)
		{
			return first->Statistics["z"] < second->Statistics["z"];
		});
	};
}

void Simple2DGraphicsEngine::Initialize(GameObject &settings)
{
	this->InitializeDefaults(settings);
	const auto &system_code = this->GetSystemCode();
	for(auto record : this->GameObjects)
	{
		auto object = record.second;
		auto sprite_game_object = new GameObject();

		sprite_game_object->Name = "sprite";
		sprite_game_object->Statistics["width"] = object->Statistics["width"];
		sprite_game_object->Statistics["height"] = object->Statistics["height"];

		auto s2dge = object->Properties[system_code];
		s2dge->Properties["sprite"] = std::move(sprite_game_object);

		auto sprite = new sf::Sprite();
		auto texture_path = s2dge->Dictionary["texture"];
		if(!_textures.HasAny(texture_path))
		{
			_textures[texture_path] = std::make_unique<sf::Texture>();

			if(!_textures[texture_path]->loadFromFile(texture_path))
			{
				cout << "Texture not found at: \"" << texture_path;
				throw;
			}
		}
		const auto &texture_ptr = _textures[texture_path].get();
		sprite->setTexture(*texture_ptr);
		s2dge->Properties["sprite"]->Data["sprite"] = std::move(sprite);
		s2dge->Properties["sprite"]->Data["texture"] = texture_ptr;
	}
	GameObject event("UpdateLayers");
	this->HandleEvent(&event);
}

void Simple2DGraphicsEngine::Update()
{
	for(const auto& record : GameObjects)
	{
		auto object = record.second;
		auto object_system = object->Properties[this->GetSystemCode()];
		object_system->Statistics["x"] = object->Statistics["x"];
		object_system->Statistics["y"] = object->Statistics["y"];
		object_system->Statistics["z"] = object->Statistics["x"];
		object_system->Statistics["x-offset"] = object->Statistics["x-offset"];
		object_system->Statistics["y-offset"] = object->Statistics["y-offset"];
	}
}

int Simple2DGraphicsEngine::HandleEvent(GameObject *event)
{
	string eventKey = event->Name;
	if(Util::HasAny(this->_universal_events,eventKey)) {
		this->_universal_events[eventKey](event);
	}
}

string Simple2DGraphicsEngine::GetSystemCode()
{
	return SystemName;
}

Vector<SrpgEngine::Framework::string> Simple2DGraphicsEngine::GetDependencies()
{
	return Vector<string>();
}

Simple2DGraphicsEngine::~Simple2DGraphicsEngine()
{
}





