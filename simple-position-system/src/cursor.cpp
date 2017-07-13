#include "cursor.hpp"
#include <iostream>

using namespace SrpgEngine;
using namespace SimplePositionSystem;
enum class InputType : int;

int Cursor::ParseInput(GameController &input,
					   InputType input_type,
					   const string &key)
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
		std::cout << "cursor cannot be null"; // TODO: Handle exceptions
		throw;
	}
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
