#include "state-machine.hpp"
#include <iostream>

using namespace SrpgEngine::Game;


StateMachine::StateMachine(string initial_state_name)
{
	this->CreateState(initial_state_name);
	this->Push(initial_state_name);
}

void StateMachine::HandleEvent(GameObject &event)
{
	(*this->context_.top()).HandleEvent(event);
}

void StateMachine::Push(const string &key)
{
	context_.push(states_[key].get());
}

void StateMachine::Pop()
{
	context_.pop();
}

StateMachine& StateMachine::CreateState(const string &name)
{
	states_[name] = std::make_unique<State>(this,name);
	return *this;
}


