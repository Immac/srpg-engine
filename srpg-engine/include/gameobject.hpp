#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "gamecommon.hpp"


namespace SrpgEngine {
namespace Game {

using namespace Framework;

class GameObject {
public:
	explicit GameObject() = default;
	explicit GameObject(string name);
	int Id;
	string Name;
	Repository<int> Statistics;
	Repository<string> Dictionary;
	Repository<void*> Data;
	Vector<GameObject*> Objects;
	Vector<string> Tags;
	Set<string> Systems;
	Repository<GameObject*> Properties;

	bool operator <(const GameObject &other){
		return this->Name.compare(other.Name) < 0;
	}

	bool operator ==(const std::string &other){
		return this->Name == other;
	}

	bool operator ==(const GameObject &other){
		return this->Name == other.Name;
	}
};

class GameObjectComparator
{
public:
	GameObjectComparator()
	{}

	bool operator ()(GameObject *first,GameObject *second) const
	{
		return first != nullptr
				&& *first < *second;
	}
};

}
}

#endif // GAMEOBJECT_HPP
