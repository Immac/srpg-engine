#ifndef SRPG_ACTION_HPP
#define SRPG_ACTION_HPP
#include <gameobject.hpp>

namespace SrpgEngine {
namespace Game {
class Position {
public:
	int x;
	int y;
};

class Action {
private:
	const Map<string,GameObject*>& world_;
	GameObject *subject_;
	GameObject *target_;
	string type_;
public:
	Action(GameObject &event,Map<string,GameObject*>& world);
};

}
}

#endif // SRPG_ACTION_HPP
