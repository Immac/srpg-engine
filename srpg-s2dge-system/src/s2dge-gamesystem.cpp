#include "s2dge-gamesystem.hpp"
#include <luautil.hpp>
#include <algorithm>
#include <memory>
#include "sprite.hpp"
#include "utilities.hpp"

using namespace SrpgEngine;
using namespace Framework;
using namespace Lua;
using namespace Game;
using namespace S2dge;

string Simple2DGraphicsEngine::SystemName = "S2DGE";

Vector<GameObject *> Simple2DGraphicsEngine::getDrawables() const
{
	return drawables_;
}

void Simple2DGraphicsEngine::InitializeDefaults(GameObject &settings)
{
	const auto& system_code = this->GetSystemCode();
	for(const auto& record : this->GameObjects)
	{
		auto& game_object = record.second;

		game_object->Systems.insert(system_code);
		const auto& s2dge = game_object->Properties[system_code];
		auto SetDefault = [&s2dge](auto key, auto value)
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

Simple2DGraphicsEngine::Simple2DGraphicsEngine(Core* core)
	:game_state_("normal"),game_core_(core)
{
	game_state_.AddState("global");

	game_state_["global"]["UpdateLayers"]
			= [this](auto& event)
	{
		this->drawables_ = Util::ExtractValues(this->GameObjects);
		const auto& sort_predicate = [](auto first, auto second)
		{
			return first->Statistics["z"] < second->Statistics["z"];
		};

		Util::Sort(drawables_,sort_predicate);
	};

	game_state_["global"]["selected_object"]
			= [this](auto &event) {
		auto& subject = event.Properties["subject"];
		std::cout << "Selected: " << subject->Name << std::endl;
	};

	game_state_["global"]["deselected_object"]
			= [this](auto &event) {
		auto& subject = event.Properties["subject"];
		std::cout << "Deselected: " << subject->Name << std::endl;
	};
}

void Simple2DGraphicsEngine::Initialize(GameObject &settings)
{
	this->InitializeDefaults(settings);
	const auto& system_code = this->GetSystemCode();
	for(auto record : this->GameObjects)
	{
		auto game_object = record.second;
		auto s2dge = game_object->Properties[system_code];
		S2dgeUtil::InitializeSprite(*game_object,*s2dge,textures_);
	}
	GameObject event("UpdateLayers");
	this->HandleEvent(event);
}

void Simple2DGraphicsEngine::Update()
{
	for(const auto& record : GameObjects)
	{
		auto game_object = record.second;
		auto system = game_object->Properties[this->GetSystemCode()];
		S2dgeUtil::UpdateSprite(*game_object,*system);
	}
}

int Simple2DGraphicsEngine::HandleEvent(GameObject &event)
{
	this->game_state_.HandleEvent(event);
	this->game_state_["global"].HandleEvent(event);
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

