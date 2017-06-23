#include "tile-position-system.hpp"

using namespace SrpgEngine::SimplePositionSystem;
using namespace SrpgEngine::Framework;
using namespace SrpgEngine::Game;

TilePositionSystem::TilePositionSystem(Core *core)
{
	this->_gameCore = core;
}

void TilePositionSystem::Initialize(GameObject &settings)
{

	this->_eventMap["MoveCursor"] = [=](GameObject *event){
		string subject_key = event->Dictionary["Subject"];
		string stat_key = event->Dictionary["Statistic"];
		int magnitude = event->Statistics["Magnitude"];
		GameObject *subject = this->GameObjects[subject_key];
		subject->Properties["TILEPOS"]->Statistics[stat_key]
				= subject->Properties["TILEPOS"]->Statistics[stat_key]
				  + magnitude;
	};
}

void TilePositionSystem::HandleVerticalCursorMovement()
{
	auto is_up_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalUp"];
	auto is_down_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalDown"];
	if(!is_up_pressed && !is_down_pressed)
	{
		this->_y_input_cooldown = _cursor_movement_cooldown + 1;
	}
	else if(this->_y_input_cooldown > _cursor_movement_cooldown)
	{
		auto event = new GameObject("MoveCursor");
		event->Dictionary["Subject"] = "Cursor";

		if(is_up_pressed)
		{
			event->Dictionary["Statistic"] = "y";
			event->Statistics["Magnitude"] -= 1;
			this->_y_input_cooldown = 0;
		}
		if(is_down_pressed)
		{
			event->Dictionary["Statistic"] = "y";
			event->Statistics["Magnitude"] += 1;
			this->_y_input_cooldown = 0;
		}
		this->HandleEvent(event);

	}
	else
	{
		this->_y_input_cooldown++;
	}
}

void TilePositionSystem::HandleHorizontaCursorlMovement()
{
	auto is_left_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalLeft"];
	auto is_right_pressed = this->_gameCore->Controllers[0]->DigitalInputs["DigitalRight"];
	if(!is_left_pressed && !is_right_pressed)
	{
		this->_x_input_cooldown = _cursor_movement_cooldown + 1;
	}
	else if(this->_x_input_cooldown > _cursor_movement_cooldown)
	{

		auto event = new GameObject("MoveCursor");
		event->Dictionary["Subject"] = "Cursor";
		if(is_left_pressed)
		{
			event->Dictionary["Statistic"] = "x";
			event->Statistics["Magnitude"] -= 1;
			this->_x_input_cooldown = 0;
		}
		if(is_right_pressed)
		{
			event->Dictionary["Statistic"] = "x";
			event->Statistics["Magnitude"] += 1;
			this->_x_input_cooldown = 0;
		}
		this->HandleEvent(event);
	}
	else
	{
		this->_x_input_cooldown++;
	}
}

void TilePositionSystem::Update()
{
	this->_x_input_cooldown = std::min(this->_x_input_cooldown,this->_y_input_cooldown);
	this->_y_input_cooldown = _x_input_cooldown;
	HandleVerticalCursorMovement();

	HandleHorizontaCursorlMovement();
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

