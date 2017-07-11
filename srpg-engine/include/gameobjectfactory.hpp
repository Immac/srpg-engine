#ifndef GAME_OBJECT_FACTORY_HPP
#define GAME_OBJECT_FACTORY_HPP
#include "gameobject.hpp"

namespace SrpgEngine {
namespace Game {

using SrpgEngine::Framework::Vector;

class GameObjectFactory {
public:
	virtual GameObject Create() = 0;
	virtual Vector<GameObject*> CreateList() = 0;
};
}
}

#endif // GAME_OBJECT_FACTORY_HPP
