#ifndef SIMPLE_TILE_MOVEMENT_SYSTEM_HPP
#define SIMPLE_TILE_MOVEMENT_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>

namespace SrpgEngine {
namespace TileMovementSystem {
using namespace Game;
using std::function;
class TileMovementSystem : public GameSystem {
private:
	Vector<string> _dependencies;
	Map<string, int> _status;
	Map<string, function<void(GameObject *)>> _eventMap;
public:
	TileMovementSystem();
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject &event) override;
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
};


}

}

#endif // SIMPLE_TILE_MOVEMENT_SYSTEM_HPP
