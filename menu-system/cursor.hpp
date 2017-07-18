#ifndef TILEPOS_CURSOR_HPP
#define TILEPOS_CURSOR_HPP
#include <gameobject.hpp>
#include <game-controller.hpp>
namespace SrpgEngine {
namespace SimpleMenuSystem {
using namespace Game;

class Cursor {
private:
	GameObject *_cursor;
	static int ParseInput(GameController &input,
						  Game::InputType input_type,
						  const string& key);
public:
	Cursor(GameObject *cursor);
	operator GameObject&() const {
		return *_cursor;
	}
	bool HandleInput(GameController &input);
};

}
}
#endif // TILEPOS_CURSOR_HPP
