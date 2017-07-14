#ifndef S2DGE_HIGHLIGHT_HPP
#define S2DGE_HIGHLIGHT_HPP
#include <gameobject.hpp>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace SrpgEngine;
using namespace Game;
class Highlight {
private:
	GameObject *_highlight;
	string _system;
	int _offscreen_x = -1;
	int _offscreen_y = -1;
public:
	Highlight(GameObject *highlight,const string& system);
	operator GameObject&() const {
		return *_highlight;
	}
	void HighlightObject(GameObject& game_object);
	void Reset();
};

}
}

#endif // S2DGE_HIGHLIGHT_HPP
