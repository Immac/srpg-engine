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
	string name_;
	StateMachine *parent_;
	HashMap<string,std::function<void(GameObject &)>> _events;
public:
	State(StateMachine *parent,const string &name)
		:name_(name),parent_(parent)
	{}
	void AddEvent(string name, std::function<void(GameObject &)> f);
	void HandleEvent(GameObject &event);


	auto& operator [] (const string &key) {
		return this->_events[key];
	}

	operator string() const{
		return name_;
	}
};

}
}

#endif // SRPGENGINE_STATE_HPP
