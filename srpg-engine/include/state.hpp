#ifndef SRPGENGINE_STATE_HPP
#define SRPGENGINE_STATE_HPP
#include "state-machine.hpp"

namespace SrpgEngine {
namespace Game
{
class StateMachine;
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

#endif // SRPGENGINE_STATE_HPP
