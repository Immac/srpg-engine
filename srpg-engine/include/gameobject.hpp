#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "gamecommon.hpp"


namespace SrpgEngine {
namespace Game {

using namespace Framework;

class GameObject {
public:
	int Id;
	string Name;
	Repository<int> Statistics;
	Repository<string> Dictionary;
	Repository<void*> Data;
	Vector<GameObject*> Objects;
	Vector<string> Tags;
	Set<string> Systems;
	Repository<GameObject*> Properties;
};

}
}

#endif // GAMEOBJECT_HPP
