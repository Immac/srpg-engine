#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>
#include <queue>
#include <gamecore.hpp>
#include <state-machine.hpp>


namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

enum class Layers;
class Cursor;
using Cursor_u_ptr = std::unique_ptr<Cursor>;
class TilePositionSystem : public GameSystem {
private:
	Map<string, std::function<void(GameObject &)>> _eventMap;
	StateMachine _game_state;
	Cursor_u_ptr _cursor;
	Core *_gameCore;

	Vector<GameObject *> _selected_game_objects;

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
	~TilePositionSystem();
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

class Cursor {
private:
	enum class InputType {
		Analog,
		Digital
	};

	GameObject *_cursor;
	static int ParseInput(GameController &input, InputType input_type,const string& key);
public:
	Cursor(GameObject *cursor);
	GameObject &GetCursor() const;
	bool HandleInput(GameController &input);
};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
