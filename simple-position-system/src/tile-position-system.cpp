#include "tile-position-system.hpp"
#include <algorithm>

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;
using namespace SrpgEngine::Util;

TilePositionSystem::TilePositionSystem(Core *core)
{
	this->_game_core = core;
}

void TilePositionSystem::Initialize(GameObject &settings)
{
	const auto &system_code = this->GetSystemCode();
	game_state_.CreateState("global")
			.CreateState("nothing_is_selected")
			.CreateState("something_is_selected");
	game_state_.Push("nothing_is_selected");

	game_state_["nothing_is_selected"]["input_pressed"]
			= [this,system_code](auto &event)
	{
		auto input_key = event.Dictionary["input"];
		auto controller_index = event.Statistics["controller"];
		if(controller_index != 0) {
			return;
		}
		if(input_key == "ButtonA") {
			auto object_under_cursor = this->GetObjectUnderCursor();
			if(object_under_cursor != nullptr) {
				this->SelectObject(*object_under_cursor);
				game_state_.Push("something_is_selected");
				this->Notify("selected_object",*object_under_cursor);
			}
		}
	};

	game_state_["something_is_selected"]["input_pressed"]
			= [this,system_code](auto &event) {
		auto input_key = event.Dictionary["input"];
		auto controller_index = event.Statistics["controller"];
		if(controller_index != 0) {
			return;
		} else if (input_key == "ButtonA") {
			this->UpdateSelectedObjects();
			auto object_under_cursor = this->GetObjectUnderCursor();
			auto selected_object = _selected_game_objects.at(0);
			if(object_under_cursor == selected_object) {
				this->DeselectObject(*selected_object);
				this->Notify("deselected_object",*selected_object);
				game_state_.Pop();
			} else if (object_under_cursor != nullptr) {
				this->DeselectObject(*selected_object);
				this->Notify("deselected_object",*selected_object);
				this->SelectObject(*object_under_cursor);
				this->Notify("selected_object",*object_under_cursor);
			}
		} else if (input_key == "ButtonB") {
			this->UpdateSelectedObjects();
			for(auto& object : _selected_game_objects) {
				this->DeselectObject(*object);
				this->Notify("deselected_object",*object);
			}
			game_state_.Pop();
		} else if (input_key == "ButtonX") {
			this->UpdateSelectedObjects();
			for(auto& game_object : this->_selected_game_objects) {
				game_object->Properties[system_code]->Statistics["y"] = 3;
				this->Notify("moved_object",*game_object);
			}
		} else if (input_key == "ButtonY") {
			//Do something ?
		}
	};

	game_state_["global"]["selected_object"]
			= [this](auto &event) {
		auto& subject = event.Properties["subject"];
		_highlight->HighlightObject(*subject);
	};

	game_state_["global"]["deselected_object"]
			= [this](auto &event) {
		_highlight->Reset();
	};

	game_state_["global"]["moved_object"]
			= [this](auto &event) {
		auto& subject = event.Properties["subject"];
		_highlight->HighlightObject(*subject);\

	};

	_cursor = std::make_unique<Cursor>(this->GameObjects["Cursor"]);
	_highlight = std::make_unique<Highlight>(
					 this->GameObjects["Highlight"],system_code);
}

void TilePositionSystem::HandleCursorMovement()
{
	auto is_up_pressed = this->_game_core->Controllers[0]->DigitalInputs["DigitalUp"];
	auto is_down_pressed = this->_game_core->Controllers[0]->DigitalInputs["DigitalDown"];
	auto is_left_pressed = this->_game_core->Controllers[0]->DigitalInputs["DigitalLeft"];
	auto is_right_pressed = this->_game_core->Controllers[0]->DigitalInputs["DigitalRight"];

	if(!is_up_pressed && !is_down_pressed && !is_left_pressed && !is_right_pressed) {
		this->_current_cooldown = _cursor_movement_cooldown + 1;
	} else if(this->_current_cooldown > _cursor_movement_cooldown) {
		if(this->_cursor->HandleInput(*this->_game_core->Controllers[0])) {
			this->_current_cooldown = 0;
		}
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

void TilePositionSystem::DeselectObject(GameObject &object)
{
	const auto& system_code = this->GetSystemCode();
	object.Properties[system_code]->Statistics["is-selected"] = 0;
}

void TilePositionSystem::SelectObject(GameObject& object)
{
	const auto& system_code = this->GetSystemCode();
	object.Properties[system_code]->Statistics["is-selected"] = 1;
}

void TilePositionSystem::Notify(const string& name,GameObject &subject)
{
	GameObject notify_deselect(name);
	notify_deselect.Properties["subject"] = &subject;
	_game_core->HandleEvent(notify_deselect);
}

GameObject *TilePositionSystem::GetObjectUnderCursor()
{
	const auto &system_code = this->GetSystemCode();
	auto cursor_system_stats
			= static_cast<GameObject>(*this->_cursor)
			  .Properties[system_code]->Statistics;

	auto selected_record_iter = Util::First(this->GameObjects,
											[&system_code,&cursor_system_stats]
											(auto record) -> bool
	{
		auto game_object = record.second;
		auto &object_system_stats = game_object->Properties[system_code]->Statistics;
		return object_system_stats["x"] == cursor_system_stats["x"]
				&& object_system_stats["y"] == cursor_system_stats["y"]
				&& object_system_stats["z"] == static_cast<int>(Layers::Ground);
	});

	return selected_record_iter != this->GameObjects.end()
								   ? selected_record_iter->second
								   : nullptr;
}

void TilePositionSystem::Update()
{
	HandleCursorMovement();

	for(const auto& record : GameObjects){
		GameObject *item = record.second;
		auto tilepos = item->Properties["TILEPOS"];

		item->Statistics["display_x"] = tilepos->Statistics["x"] * this->_tile_size;
		item->Statistics["display_y"] = tilepos->Statistics["y"] * this->_tile_size;
		item->Statistics["x"] = tilepos->Statistics["x"];
		item->Statistics["y"] = tilepos->Statistics["y"];
		item->Statistics["z"] = tilepos->Statistics["z"];
		item->Statistics["x-offset"] = tilepos->Statistics["x-offset"];
		item->Statistics["y-offset"] = tilepos->Statistics["y-offset"];
	}
}

int TilePositionSystem::HandleEvent(GameObject &event)
{
	game_state_["global"].HandleEvent(event);
	game_state_.HandleEvent(event);
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

