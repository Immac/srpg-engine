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
			= [this,system_code](const auto &event){
		string subject_key = event->Dictionary["Subject"];
		string stat_key = event->Dictionary["Statistic"];
		int magnitude = event->Statistics["Magnitude"];
		GameObject *subject = this->GameObjects[subject_key];
		subject->Properties[system_code]->Statistics[stat_key]
				= subject->Properties[system_code]->Statistics[stat_key]
				  + magnitude;
	};

	this->_eventMap["SelectObject"]
			= [this,system_code](const auto &event) {
		const auto &x = event->Statistics["x"];
		const auto &y = event->Statistics["y"];
		const auto &z = event->Statistics["z"];
		auto vec = ExtractValues(this->GameObjects);
						  RemoveIf(vec,[&system_code,&x,&y,&z](GameObject *go){
							  auto &stats = go->Properties[system_code]->Statistics;
							  return stats["x"] != x
									  || stats["y"] != y
									  || stats["z"] != z;
						  });
		for(auto &object : vec){
			object->Properties[system_code]->Statistics["is-selected"] = 1;
		}
	};

	this->_eventMap["SetObjectCoordinate"] = [this,system_code](const auto &event){
		string subject_key = event->Dictionary["Subject"];
		string stat_key = event->Dictionary["Statisic"];
		int value = event->Statistics["Value"];
		GameObject * subject = this->GameObjects[subject_key];
		subject->Properties[system_code]->Statistics[stat_key]
				= value;
	};

	this->_eventMap["SetSelectedCoordinate"] = [this,system_code](const auto &event){
		this->UpdateSelectedObjects();
		for(auto game_object : this->_selectedGameObjects)
		{
			((GameObject*)game_object)
					->Properties[system_code]
					->Statistics["y"] = 3;
		}
	};

	this->_eventMap["SelectObjectUnderCursor"] = [this,system_code](const auto &event) {
		const auto &cursor = this->GameObjects["Cursor"];
		auto x = cursor->Properties[system_code]->Statistics["x"];
		auto y = cursor->Properties[system_code]->Statistics["y"];
		auto z = Layers::Ground;
		GameObject selection_event("SelectObject");
		selection_event.Statistics["x"] = x;
		selection_event.Statistics["y"] = y;
		selection_event.Statistics["z"] = static_cast<int>(z);
		this->_gameCore->HandleEvent(&selection_event);
		int i = 0;
	};

	this->_eventMap["DeselectAll"] = [this,system_code](const auto &event){
		this->UpdateSelectedObjects();
		for(const auto& object:this->_selectedGameObjects)
		{
			object->Properties[system_code]->Statistics["is-selected"] = 0;
			int i = 0;
		}
	};
}

void TilePositionSystem::HandleVerticalCursorMovement()
{
	auto is_up_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalUp"];
	auto is_down_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalDown"];
	if(!is_up_pressed && !is_down_pressed)
	{
		this->yInputCooldown = _cursorMovementCooldown + 1;
	}
	else if(this->yInputCooldown > _cursorMovementCooldown)
	{
		auto event = new GameObject("MoveCursor");
		event->Dictionary["Subject"] = "Cursor";

		if(is_up_pressed)
		{
			event->Dictionary["Statistic"] = "y";
			event->Statistics["Magnitude"] -= 1;
			this->yInputCooldown = 0;
		}
		if(is_down_pressed)
		{
			event->Dictionary["Statistic"] = "y";
			event->Statistics["Magnitude"] += 1;
			this->yInputCooldown = 0;
		}
		this->HandleEvent(event);

	}
	else
	{
		this->yInputCooldown++;
	}
}

void TilePositionSystem::HandleHorizontaCursorlMovement()
{
	auto is_left_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalLeft"];
	auto is_right_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalRight"];
	if(!is_left_pressed && !is_right_pressed)
	{
		this->_xInpuntCooldown = _cursorMovementCooldown + 1;
	}
	else if(this->_xInpuntCooldown > _cursorMovementCooldown)
	{

		auto event = new GameObject("MoveCursor");
		event->Dictionary["Subject"] = "Cursor";
		if(is_left_pressed)
		{
			event->Dictionary["Statistic"] = "x";
			event->Statistics["Magnitude"] -= 1;
			this->_xInpuntCooldown = 0;
		}
		if(is_right_pressed)
		{
			event->Dictionary["Statistic"] = "x";
			event->Statistics["Magnitude"] += 1;
			this->_xInpuntCooldown = 0;
		}
		this->HandleEvent(event);
	}
	else
	{
		this->_xInpuntCooldown++;
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
	this->_selectedGameObjects = selected_game_objects;
}

void TilePositionSystem::Update()
{
	this->_xInpuntCooldown = std::min(this->_xInpuntCooldown,this->yInputCooldown);
	this->yInputCooldown = _xInpuntCooldown;
	auto is_a_pressed = this->_gameCore->Controllers[0]->DigitalInputs["ButtonA"];
	if(is_a_pressed){
		GameObject event("SelectObjectUnderCursor");
		this->_gameCore->HandleEvent(&event);
	}
	HandleVerticalCursorMovement();
	HandleHorizontaCursorlMovement();
	for(const auto& record : GameObjects){
		GameObject *item = record.second;
		auto tilepos = item->Properties["TILEPOS"];
		item->Statistics["x"] = tilepos->Statistics["x"] * this->_tileSize;
		item->Statistics["y"] = tilepos->Statistics["y"] * this->_tileSize;
		item->Statistics["z"] = tilepos->Statistics["z"];
		item->Statistics["x-offset"] = tilepos->Statistics["x-offset"];
		item->Statistics["y-offset"] = tilepos->Statistics["y-offset"];
	}
}

int TilePositionSystem::HandleEvent(GameObject *event)
{

	string eventKey = event->Name;
	if(_eventMap.find(eventKey)!=_eventMap.end()){
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

