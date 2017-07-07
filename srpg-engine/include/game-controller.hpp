#ifndef SRPG_GAME_CONTROLLER_HPP
#define SRPG_GAME_CONTROLLER_HPP
#include <unordered_map>
#include "gamecommon.hpp"

namespace SrpgEngine {
namespace Game {
using namespace Framework;
class GameController {
private:
public:
	GameController();
	HashMap<string,bool> DigitalInputs;
	HashMap<string,int> AnalogInputs;
};

}
}

#endif // SRPG_GAME_CONTROLLER_HPP
