#ifndef SRPG_GAME_CORE_HPP
#define SRPG_GAME_CORE_HPP

#include "gamecommon.hpp"
#include "gamesystem.hpp"

namespace SrpgEngine {
namespace Game {

using namespace Framework;

class Core {
private:
	enum Status{
		Stopped,
		Running
	};

	Status _status = Stopped;
public:
	Map<string,GameSystem*> Systems;
	Map<string,GameObject*> Objects;
	int Run();
};

}
}

#endif // SRPG_GAME_CORE_HPP
