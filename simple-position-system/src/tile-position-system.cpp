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
	this->_game_state.AddState("global")
			.AddState("nothing_is_selected")
			.AddState("something_is_selected");
	this->_game_state.GoTo("nothing_is_selected");

	this->_game_state["nothing_is_selected"]["input_pressed"]
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
				object_under_cursor
						->Properties[system_code]->Statistics["is-selected"]
						= 1;
				this->_game_state.GoTo("something_is_selected");
				GameObject e("selected_something");
				this->_game_core->HandleEvent(e);
			}
		}
	};

	this->_game_state["something_is_selected"]["input_pressed"]
			= [this,system_code](auto &event) {
		auto input_key = event.Dictionary["input"];
		auto controller_index = event.Statistics["controller"];
		if(controller_index != 0) {
			return;
		} else if (input_key == "ButtonA") {
			//TODO: Deselect if same, select new if other
			this->UpdateSelectedObjects();
			auto object_under_cursor = this->GetObjectUnderCursor();
			auto selected_object = this->_selected_game_objects.at(0);
			if(object_under_cursor == selected_object) {
				selected_object->Properties[system_code]->Statistics["is-selected"] = 0;
				GameObject new_event("deselected_unit");
				_game_core->HandleEvent(new_event);
				_game_state.GoTo("nothing_is_selected");
			}
		} else if (input_key == "ButtonB") {
			this->UpdateSelectedObjects();
			for(auto& object:this->_selected_game_objects) {
				object->Properties[system_code]->Statistics["is-selected"] = 0;
			}

			_game_state.GoTo("nothing_is_selected");
		} else if (input_key == "ButtonX") {
			//Do example move
		} else if (input_key == "ButtonY") {
			//Do something ?
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
		this->_game_core->HandleEvent(selection_event);
	};

	this->_eventMap["DeselectAll"] = [this,system_code](const auto &event){
		this->UpdateSelectedObjects();
		for(auto& object:this->_selected_game_objects)
		{
			object->Properties[system_code]->Statistics["is-selected"] = 0;
		}
	};

	this->_cursor = std::make_unique<Cursor>(this->GameObjects["Cursor"]);
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

GameObject *TilePositionSystem::GetObjectUnderCursor()
{
	const auto &system_code = this->GetSystemCode();
	auto cursor_system_stats
			= this->_cursor->GetCursor().Properties[system_code]->Statistics;

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
		item->Statistics["x"] = tilepos->Statistics["x"] * this->_tile_size;
		item->Statistics["y"] = tilepos->Statistics["y"] * this->_tile_size;
		item->Statistics["z"] = tilepos->Statistics["z"];
		item->Statistics["x-offset"] = tilepos->Statistics["x-offset"];
		item->Statistics["y-offset"] = tilepos->Statistics["y-offset"];
	}
}

int TilePositionSystem::HandleEvent(GameObject &event)
{
	_game_state["global"].HandleEvent(event);
	_game_state.HandleEvent(event);
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

int Cursor::ParseInput(GameController &input, Cursor::InputType input_type, const string &key)
{
	switch (input_type) {
	case InputType::Analog: {
			return input.AnalogInputs[key];
		} break;
	case InputType::Digital: {
			return input.DigitalInputs[key] ? 1 : 0;
		} break;
	}
}

Cursor::Cursor(GameObject *cursor)
	:_cursor(cursor)
{
	if(this->_cursor == nullptr) {
		std::cout << "cursor cannot be null";
		throw;
	}
}

GameObject &Cursor::GetCursor() const
{
	return *this->_cursor;
}

bool Cursor::HandleInput(GameController &input)
{
	auto ParseDigital = [&input](const auto &key) {
		return Cursor::ParseInput(input,InputType::Digital,key);
	};

	auto y_displacement = ParseDigital("DigitalDown") - ParseDigital("DigitalUp");
	auto x_displacement = ParseDigital("DigitalRight") - ParseDigital("DigitalLeft");

	auto& cursor_system_stats = this->_cursor->Properties["TILEPOS"]->Statistics;
	cursor_system_stats["x"] += x_displacement;
	cursor_system_stats["y"] += y_displacement;
	return x_displacement != 0 || y_displacement !=0;
}
