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
	Map<string, std::function<void(GameObject *)>> _eventMap;
	std::queue<std::function<void(GameObject *)>> _updateQueue;
	Core *_gameCore;
	Vector<GameObject *> _selected_game_objects;
	int _current_cooldown = 0;
	int _current_startup = 0;
	int _cursor_movement_cooldown = 15;
	int _cursor_startup = 4;
	int _tile_size = 64;

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
	void HandleCursorMovement();
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

enum class Facing : int {
	North,
	South,
	East,
	West
};

class InputFrameController {
private:
	int current_cooldown = 0;
	int current_startup = 0;
	int cooldown = 3;
	int startup = 3;
public:
	Vector<GameController *> v;
	bool PerformAction(GameController &controller);

};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
