#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>

namespace SrpgEngine {
namespace ActionSystem {
using namespace Game;
using namespace Framework;
class SimpleActionSystem : public GameSystem {
private:
	string _execute_key = "execute";

	// GameSystem interface
public:
	void Initialize(GameObject &settings) override;
	void Update() override;
	string GetSystemCode() override;
};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
