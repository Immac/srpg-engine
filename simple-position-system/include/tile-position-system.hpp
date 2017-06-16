#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>
#include <queue>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

class TilePositionSystem : public GameSystem {
private:
	int status = 0;
	Map<string, std::function<void(GameObject *)>> _eventMap;
	std::queue<std::function<void(GameObject *)>> _updateQueue;
	GameObject *_cursor;
public:
	TilePositionSystem();
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject *event);
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
private:
	TilePositionSystem (const &TilePositionSystem){}
	TilePositionSystem& operator=(const &TilePositionSystem){}
};



}
}



#endif // SRPG_ACTION_SYSTEM_HPP
