#ifndef SRPG_STATE_MACHINE_HPP
#define SRPG_STATE_MACHINE_HPP
#include "gamecommon.hpp"
#include "gameobject.hpp"
#include <memory>

namespace SrpgEngine {
namespace Game {
using namespace Framework;
class State;
using State_u_ptr = std::unique_ptr<State>;

class StateMachine
{
private:
	HashMap<string,State_u_ptr> _states;
	State * _current_state;
public:

	StateMachine(string initial_state_name = "Init");
	void HandleEvent(GameObject &event); //TODO: add a const parameter version
	void GoTo(const string& key);
	StateMachine& AddState(const string &name);

	auto& operator [] (const string &key) {
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
	void HandleEvent(GameObject &event);


	auto& operator [] (const string &key) {
		return this->_events[key];
	}

	operator string() const{
		return _name;
	}
};
}
}


#endif // SRPG_STATE_MACHINE_HPP
