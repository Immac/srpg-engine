#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamecore.hpp>
#include <gamesystem.hpp>
#include <state-machine.hpp>

namespace SrpgEngine {
namespace ActionSystem {
using namespace Game;
using namespace Framework;
class SimpleActionSystem : public GameSystem {
private:
	StateMachine context_;
	Core* game_core_;
public:	
	void Initialize(GameObject &settings) override;
	void Update() override;
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
	int HandleEvent(GameObject& event) override;
};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
