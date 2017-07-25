#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>
#include <queue>
#include <gamecore.hpp>
#include <state-machine.hpp>
#include <list>
#include <option.hpp>
#include "action.hpp"
#include "cursor.hpp"
#include "highlight.hpp"

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

enum class Layers : int;
class Cursor;
class TilePositionSystem : public GameSystem {
private:
	Map<string, std::function<void(GameObject &)>> _eventMap;
	StateMachine context_;
	UniquePtr<Cursor> cursor_;
	UniquePtr<Highlight> _highlight;
	Action *action_in_progress_;

	Core *core_;
	Vector<GameObject *> selected_game_objects_;

	int _current_cooldown = 0;
	int _cursor_movement_cooldown = 15;
	int _tile_size = 64;

public:
	TilePositionSystem(Core *core);
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject &event);
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
	TilePositionSystem (const &TilePositionSystem) = delete;
	TilePositionSystem& operator=(const &TilePositionSystem) = delete;
private:

	void HandleCursorMovement();
	void HandleHorizontaCursorlMovement();
	void UpdateSelectedObjects();
	void DeselectObject(GameObject &object);
	void SelectObject(GameObject &object);
	void Notify(const string& name, GameObject& subject);
	void Notify(GameObject& event, GameObject& subject);
	void HighlightActionRange(Action &action);
	GameObject *GetObjectUnderCursor();
	Vector<GameObject*> GetObjectsUnderCursor();
	void ResetTargets();
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

}
}



#endif // SRPG_ACTION_SYSTEM_HPP

