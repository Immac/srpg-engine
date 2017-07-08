#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP
#include "gameobject.hpp"
#include "observer.hpp"
#include <iostream>

namespace SrpgEngine {
namespace Game {
using namespace Framework;



class GameSystem
{
public:
	virtual void Initialize(GameObject &settings) = 0;
	virtual void Update() = 0;
	virtual string GetSystemCode() = 0;
	virtual Vector<string> GetDependencies() = 0;
	virtual int HandleEvent(GameObject &event) = 0;

	Map<string,GameObject*> GameObjects;
};
}
}

#endif // GAME_SYSTEM_HPP
