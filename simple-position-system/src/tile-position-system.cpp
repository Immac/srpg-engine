#include "tile-position-system.hpp"
#include <algorithm>

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;
using namespace SrpgEngine::Util;

TilePositionSystem::TilePositionSystem(Core *core)
{
	this->_gameCore = core;
}

void TilePositionSystem::Initialize(GameObject &settings)
{
	const auto &system_code = this->GetSystemCode();
	this->_eventMap["MoveCursor"]
			= [this,system_code](auto &event){
		const auto &subject_key = event.Dictionary["Subject"];
		const auto &stat_key = event.Dictionary["Statistic"];
		int magnitude = event.Statistics["Magnitude"];
		auto subject = this->GameObjects[subject_key];
		subject->Properties[system_code]->Statistics[stat_key]
				= subject->Properties[system_code]->Statistics[stat_key]
				  + magnitude;
	};

	this->_eventMap["SelectObject"]
			= [this,system_code](auto &event) {
		const auto &x = event.Statistics["x"];
		const auto &y = event.Statistics["y"];
		const auto &z = event.Statistics["z"];
		auto vec = Util::ExtractValues(this->GameObjects);
		Util::RemoveIf(vec,[&system_code,&x,&y,&z](GameObject *go){
			auto &stats = go->Properties[system_code]->Statistics;
			return stats["x"] != x
					|| stats["y"] != y
					|| stats["z"] != z;
		});
		for(auto &object : vec){
			object->Properties[system_code]->Statistics["is-selected"] = 1;
		}
	};

	this->_eventMap["SetObjectCoordinate"] = [this,system_code](auto &event) {
		auto subject_key = event.Dictionary["Subject"];
		auto stat_key = event.Dictionary["Statisic"];
		auto value = event.Statistics["Value"];
		auto subject = this->GameObjects[subject_key];
		subject->Properties[system_code]->Statistics[stat_key]
				= value;
	};

	this->_eventMap["SetSelectedCoordinate"] = [this,system_code](auto &event){
		this->UpdateSelectedObjects();

		for(auto game_object : this->_selected_game_objects) {
			game_object->Properties[system_code]->Statistics["y"] = 3;
		}
	};

	this->_eventMap["SelectObjectUnderCursor"] = [this,system_code](auto &event) {
		const auto &cursor = this->GameObjects["Cursor"];
		auto x = cursor->Properties[system_code]->Statistics["x"];
		auto y = cursor->Properties[system_code]->Statistics["y"];
		auto z = Layers::Ground;
		GameObject selection_event("SelectObject");
		selection_event.Statistics["x"] = x;
		selection_event.Statistics["y"] = y;
		selection_event.Statistics["z"] = static_cast<int>(z);
		this->_gameCore->HandleEvent(selection_event);
		int i = 0;
	};

	this->_eventMap["DeselectAll"] = [this,system_code](const auto &event){
		this->UpdateSelectedObjects();
		for(auto& object:this->_selected_game_objects)
		{
			object->Properties[system_code]->Statistics["is-selected"] = 0;
			int i = 0;
		}
	};

}

void TilePositionSystem::HandleCursorMovement()
{
	auto is_up_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalUp"];
	auto is_down_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalDown"];
	auto is_left_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalLeft"];
	auto is_right_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalRight"];

	if(!is_up_pressed && !is_down_pressed && !is_left_pressed && !is_right_pressed) {
		this->_current_cooldown = _cursor_movement_cooldown + 1;
	} else if(this->_current_cooldown > _cursor_movement_cooldown) {
		GameObject event("MoveCursor");
		event.Dictionary["Subject"] = "Cursor";

		if(is_up_pressed) {
			event.Dictionary["Statistic"] = "y";
			event.Statistics["Magnitude"] -= 1;
			this->_current_cooldown = 0;
		}
		if(is_down_pressed) {
			event.Dictionary["Statistic"] = "y";
			event.Statistics["Magnitude"] += 1;
			this->_current_cooldown = 0;
		}

		this->HandleEvent(event);
		event.Statistics["Magnitude"] = 0;
		if(is_left_pressed) {
			event.Dictionary["Statistic"] = "x";
			event.Statistics["Magnitude"] -= 1;
			this->_current_cooldown = 0;
		}
		if(is_right_pressed) {
			event.Dictionary["Statistic"] = "x";
			event.Statistics["Magnitude"] += 1;
			this->_current_cooldown = 0;
		}
		this->HandleEvent(event);
	} else {
		this->_current_cooldown++;
	}
}

void TilePositionSystem::UpdateSelectedObjects()
{
	auto selected_game_objects = ExtractValues(this->GameObjects);
	auto system_code = this->GetSystemCode();
	RemoveIf(selected_game_objects,
			 [&system_code](const auto &record) -> bool
	{
		auto isSelected = static_cast<bool>(record->Properties[system_code]
											->Statistics["is-selected"]);
		return !isSelected;
	});
	this->_selected_game_objects = selected_game_objects;
}

void TilePositionSystem::Update()
{
	auto is_a_pressed = this->_gameCore->Controllers[0]->DigitalInputs["ButtonA"];
	auto is_b_pressed = this->_gameCore->Controllers[0]->DigitalInputs["ButtonB"];
	if(is_a_pressed) {
		GameObject event("SelectObjectUnderCursor");
		this->_gameCore->HandleEvent(event);
	}
	if(is_b_pressed) {
		GameObject event("DeselectAll");
		this->_gameCore->HandleEvent(event);
	}
	HandleCursorMovement();
	for(const auto& record : GameObjects){
		GameObject *item = record.second;
		auto tilepos = item->Properties["TILEPOS"];
		item->Statistics["x"] = tilepos->Statistics["x"] * this->_tile_size;
		item->Statistics["y"] = tilepos->Statistics["y"] * this->_tile_size;
		item->Statistics["z"] = tilepos->Statistics["z"];
		item->Statistics["x-offset"] = tilepos->Statistics["x-offset"];
		item->Statistics["y-offset"] = tilepos->Statistics["y-offset"];
	}
}

int TilePositionSystem::HandleEvent(GameObject &event)
{
	string eventKey = event.Name;
	if(_eventMap.find(eventKey)!=_eventMap.end()) {
		_eventMap[eventKey](event);
	}
}

string TilePositionSystem::GetSystemCode()
{
	return "TILEPOS";
}

Vector<string> TilePositionSystem::GetDependencies()
{
	return Vector<string>();
}


bool InputFrameController::PerformAction(GameController &controller)
{
	//for(const auto &input )
}
