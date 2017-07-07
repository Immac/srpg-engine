#include "state-machine.hpp"
using namespace SrpgEngine::Game;


StateMachine::StateMachine(string initial_state_name)
{
	this->_states[initial_state_name] = std::make_unique<State>(this,initial_state_name);
	this->_current_state = this->_states[initial_state_name].get();
}

void StateMachine::HandleEvent(GameObject &event)
{
	(*this->_current_state).HandleEvent(event);
}

void State::HandleEvent(GameObject &event)
{
	this->_events[event.Name](event);
}
