#include <iostream>
#include "highlight.hpp"

using namespace SrpgEngine::SimpleMenuSystem;

Highlight::Highlight(GameObject* highlight, const string& system)
	:_highlight(highlight),_system(system)
{
	if(_highlight == nullptr) {
		std::cout << "highlight cannot be null";
		throw;
	}
}

void Highlight::HighlightObject(GameObject& game_object)
{
	_highlight->Properties[_system]->Statistics["x"]
			= game_object.Properties[_system]->Statistics["x"];
	_highlight->Properties[_system]->Statistics["y"]
			= game_object.Properties[_system]->Statistics["y"];
}

void Highlight::Reset()
{
	_highlight->Properties[_system]->Statistics["x"] = _offscreen_x;
	_highlight->Properties[_system]->Statistics["y"] = _offscreen_y;
}


