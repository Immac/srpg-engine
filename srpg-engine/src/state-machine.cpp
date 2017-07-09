#include "state-machine.hpp"
using namespace SrpgEngine::Game;


StateMachine::StateMachine(string initial_state_name)
{
	this->AddState(initial_state_name);
	this->_current_state = this->_states[initial_state_name].get();
}

void StateMachine::HandleEvent(GameObject &event)
{
	(*this->_current_state).HandleEvent(event);
}

StateMachine& StateMachine::AddState(const string &name)
{
	this->_states[name] = std::make_unique<State>(this,name);
	return *this;
}


void State::HandleEvent(GameObject &event)
{
	if(Util::HasAny(this->_events,event.Name)) {
		this->_events[event.Name](event);
	}
}
