#ifndef SRPG_GAME_CORE_HPP
#define SRPG_GAME_CORE_HPP

#include <functional>
#include <unordered_map>

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
	enum Status{
		Stopped,
		Initializing,
		Running
	};
	const int _controller_count = 16;
	Status _status = Stopped;
	void LoadSystemObjects();
	void LoadCoreObjects();
	ConfigurationManager _configurationManager;


public:
	Core();
	Map<string,GameSystem*> SystemMap;
	Map<string,GameObject*> ObjectMap;
	StateMachine GameState;
	HashMap<int,GameController *> Controllers;

	int HandleEvent(GameObject &event);
	int Init();
	int Update();
};

}
}

#endif // SRPG_GAME_CORE_HPP
