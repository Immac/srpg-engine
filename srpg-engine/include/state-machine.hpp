#ifndef SRPG_STATE_MACHINE_HPP
#define SRPG_STATE_MACHINE_HPP
#include "gamecommon.hpp"
#include "gameobject.hpp"
#include "state.hpp"
#include <memory>
#include <stack>

namespace SrpgEngine {
namespace Game {
using namespace Framework;
class State;
using State_u_ptr = std::unique_ptr<State>;

class StateMachine
{
private:
	HashMap<string,State_u_ptr> states_;

	State * current_state_;
	std::stack<State*> context_;
public:

	StateMachine(string initial_state_name = "Init");
	void HandleEvent(GameObject &event); //TODO: add a const parameter version
	void Push(const string& key);
	void Pop();
	StateMachine& CreateState(const string &name);

	auto& operator [] (const string &key) {
		return *this->states_[key];
	}
};




}
}


#endif // SRPG_STATE_MACHINE_HPP
