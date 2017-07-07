#ifndef SRPG_STATE_MACHINE_HPP
#define SRPG_STATE_MACHINE_HPP
#include "gamecommon.hpp"
#include "gameobject.hpp"

namespace SrpgEngine {
namespace Game {
using namespace Framework;
class State;
class StateMachine
{
private:
	HashMap<string,State*> _states;
public:
	void HandleEvent(GameObject &event);
	void AddState(State &state);
	void AddState(State* state);

	auto& operator [] (string key) {
		return *this->_states[key];
	}
};

class State
{
private:
	string _name;
	StateMachine *_parent_state_machine;
	HashMap<string,std::function<void(GameObject &)>> _events;
public:
	State(StateMachine *parent,const string &name)
		:_parent_state_machine(parent),_name(name)
	{}
	void AddEvent(string name, std::function<void(GameObject &)> f);

	auto& operator [] (string key) {
		return this->_events[key];
	}

	operator string() const{
		return _name;
	}
};
}
}


#endif // SRPG_STATE_MACHINE_HPP