#ifndef SRPG_GAME_CORE_HPP
#define SRPG_GAME_CORE_HPP

#include <functional>
#include "configuration-manager.hpp"
#include "gamecommon.hpp"
#include "gamesystem.hpp"

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

	Status _status = Stopped;
	void LoadSystemObjects();
	void LoadCoreObjects();
	ConfigurationManager _configurationManager;
public:

	Core();
	Map<string,GameSystem*> SystemMap;
	Map<string,GameObject*> ObjectMap;
	Map<string, std::function<void()>> EventMap;
	int HandleEvent(string s);
	int Init();
	int Run();
};

}
}

#endif // SRPG_GAME_CORE_HPP
