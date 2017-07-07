#include "state-machine.hpp"
using namespace SrpgEngine::Game;


void StateMachine::HandleEvent(GameObject &event)
{

}

void StateMachine::AddState(State &state)
{
	this->_states[state] = &state;
}

void StateMachine::AddState(State *state)
{
	this->_states[*state] = state;
}

void State::AddEvent(string name,std::function<void(GameObject &)> f)
{
	this->_events[name] = f;
}
