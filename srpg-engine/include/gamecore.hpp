#ifndef SRPG_GAME_CORE_HPP
#define SRPG_GAME_CORE_HPP

#include <functional>
#include "configuration-manager.hpp"
#include "gamecommon.hpp"
#include "gamesystem.hpp"
#include "game-controller.hpp"
#include "state-machine.hpp"

namespace SrpgEngine {
namespace Game {

using namespace Framework;

class Core {
private:
	const int controller_count_ = 16;
	void LoadSystemObjects();
	void LoadCoreObjects();
	ConfigurationManager configuration_manage_;
	StateMachine game_state_;
public:
	Core();
	Map<string,GameSystem*> SystemMap;
	Map<string,GameObject*> ObjectMap;
	HashMap<int,GameController *> Controllers;

	void HandleEvent(GameObject &event);
	void Init();
	void Update();
};

}
}

#endif // SRPG_GAME_CORE_HPP
