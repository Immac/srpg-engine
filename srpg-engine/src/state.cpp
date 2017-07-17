#include "state.hpp"
using namespace SrpgEngine;
using namespace Game;
void State::HandleEvent(GameObject &event)
{
	if(Util::HasAny(this->_events,event.Name)) {
		this->_events[event.Name](event);
	}
}
