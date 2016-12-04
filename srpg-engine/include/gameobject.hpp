#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "gamecommon.hpp"


namespace SrpgEngine {
namespace Game {

using namespace Framework;

class GameObject {
public:
	string Name;
	Repository<int> Statistics;
	Repository<string> Dictionary;
	Vector<GameObject*> Objects;
	Vector<string> Tags;
	Repository<GameObject*> Properties;
};

}
}

#endif // GAMEOBJECT_HPP
