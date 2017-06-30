#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>
#include <queue>
#include <gamecore.hpp>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

enum class Layers;

class TilePositionSystem : public GameSystem {
private:
	int status = 0;
	Map<string, std::function<void(GameObject *)>> _eventMap;
	std::queue<std::function<void(GameObject *)>> _updateQueue;
	GameObject *_cursor;
	Core *_gameCore;
	Vector<GameObject *> _selectedGameObjects;
	int _xInpuntCooldown = 0;
	int yInputCooldown = 0;
	int _cursorMovementCooldown = 4;
	int _tileSize = 64;
public:
	TilePositionSystem(Core *core);
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject *event);
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;

private:
	TilePositionSystem (const &TilePositionSystem){}
	TilePositionSystem& operator=(const &TilePositionSystem){}
	void HandleVerticalCursorMovement();
	void HandleHorizontaCursorlMovement();
	void UpdateSelectedObjects();
};

enum class Layers : int {
	Background,
	Tile,
	Ground,
	Air,
	Foreground = 100,
	Cursor = 1000
};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
