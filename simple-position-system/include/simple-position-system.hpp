#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

class TilePositionSystem : public GameSystem {
private:

	// GameSystem interface
public:
	void Initialize(GameObject &settings) override;
	void Update() override;
	string GetSystemCode() override;
};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
