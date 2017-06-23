#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>
#include <queue>
#include <gamecore.hpp>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

class TilePositionSystem : public GameSystem {
private:
	int status = 0;
	Map<string, std::function<void(GameObject *)>> _eventMap;
	std::queue<std::function<void(GameObject *)>> _updateQueue;
	GameObject *_cursor;
	Core *_gameCore;
	int _x_input_cooldown = 0;
	int _y_input_cooldown = 0;
	int _cursor_movement_cooldown = 4;
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
};



}
}



#endif // SRPG_ACTION_SYSTEM_HPP
