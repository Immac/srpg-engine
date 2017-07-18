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

	for(const auto& record : this->GameObjects)
	{

		auto& game_object = record.second;

		const auto& graphics = game_object->Properties[vocabulary.graphics];
		const auto& position = graphics->Properties[vocabulary.position];
		const auto& size = graphics->Properties[vocabulary.size];

		auto SetDefault = [](auto& container ,auto key, auto value)
		{
			if(!container->Statistics.HasAny(key)) {
				container->Statistics[key] = value;
			}
		};
		SetDefault(position,"x",0);
		SetDefault(position,"y",0);
		SetDefault(position,"x-offset",0);
		SetDefault(position,"y-offset",0);
		SetDefault(graphics,"red",255);
		SetDefault(graphics,"green",255);
		SetDefault(graphics,"blue",255);
		SetDefault(graphics,"alpha",255);
		SetDefault(size,"width",64);
		SetDefault(size,"heigth",64);
	}
}

Simple2DGraphicsEngine::Simple2DGraphicsEngine(Core* core)
	:game_state_("normal"),game_core_(core)
{
	game_state_.CreateState("global");

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
		S2dgeUtil::InitializeSprite(*game_object,textures_);
	}
	GameObject event("UpdateLayers");
	this->HandleEvent(event);
}

void Simple2DGraphicsEngine::Update()
{
//	for(const auto& record : GameObjects)
//	{
//		auto game_object = record.second;
//		auto system = game_object->Properties[this->GetSystemCode()];
//		S2dgeUtil::UpdateSprite(*game_object,*system);
//	}
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

