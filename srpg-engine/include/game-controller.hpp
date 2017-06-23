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
	std::unordered_map<string,bool> DigitalInputs;
	std::unordered_map<string,int> AnalogInputs;
};

}
}

#endif // SRPG_GAME_CONTROLLER_HPP
