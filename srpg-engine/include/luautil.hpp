#ifndef SRPG_LUA_UTIL_HPP
#define SRPG_LUA_UTIL_HPP
#include <lua.hpp>
#include <common.hpp>
#include <iostream>
#include "gameobjectfactory.hpp"
#include <sol.hpp>

namespace SrpgEngine {
namespace Framework {
namespace Lua {
using Game::GameObjectFactory;
using Game::GameObject;
using Framework::string;
class LuaGameObjectFactory : public GameObjectFactory {
private:
	sol::state *_state;
	Repository<int> getStats(sol::table object);
	Repository<string> getDictionary(sol::table object);
	Vector<string> getPropertyNames(sol::table object);
	Vector<string> getTags(sol::table object);

public:
	LuaGameObjectFactory(sol::state *state)
		:_state(state)
		{}
	GameObject Create();
	Vector<SrpgEngine::Framework::Lua::GameObject *> CreateList();

};

template<class T>
Repository<T> BuildRepository(sol::table root){
	Repository<T> repo;
	for(int i = 1; root[i] ; i++)
	{
		auto cursor = root[i];
		for(int j = 1; j <=1; j++)
		{
			repo[cursor[j]] = cursor[j+1];
		}
	}

	return repo;
}

template<class T>
Vector<T> BuildVector(sol::table root){
	Vector<T> vec;
	for(int i = 1; root[i]; i++){
		T cursor = root[i];
		vec.push_back(cursor);
	}
	return vec;
}

}
}
}

#endif // SRPG_LUA_UTIL_HPP
