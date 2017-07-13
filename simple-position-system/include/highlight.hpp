#ifndef S2DGE_HIGHLIGHT_HPP
#define S2DGE_HIGHLIGHT_HPP
#include <gameobject.hpp>

namespace SrpgEngine {
namespace S2dge {
using namespace SrpgEngine;
using namespace Game;
class Highlight {
private:
	GameObject *_highlight;
public:
	Highlight(GameObject *highlight);
	operator GameObject&() const {
		return *_highlight;
	}
	GameObject &AsGameObject();

};

}
}

#endif // S2DGE_HIGHLIGHT_HPP
