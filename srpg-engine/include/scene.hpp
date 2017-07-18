#ifndef SRPG_MENU_SCENE_HPP
#define SRPG_MENU_SCENE_HPP
#include <gameobject.hpp>
#include <state-machine.hpp>

namespace SrpgEngine {
namespace Game {

class Act;

using namespace Game;
using namespace Framework;

class Scene {
private:
	StateMachine context_;
	Queue<Act*> actors_;
public:
	void HandleEvent(GameObject& event);
};

class Act : public GameObject {
private:
	Vector<GameObject *> actors_;
public:
	Act(Vector<GameObject*> actors);
};

}
}

#endif // SRPG_MENU_SCENE_HPP
