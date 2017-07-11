#define SOL_USING_CXX_LUA 1
#include <luautil.hpp>
#include <iostream>
#include <sol.hpp>
#include "luautil.hpp"

using SrpgEngine::Framework::Lua::LuaGameObjectFactory;
using SrpgEngine::Framework::Vector;
using SrpgEngine::Framework::string;

int main(){

	sol::state game_state;
	std::string _config_filepath = "object.go";
	game_state.open_libraries(sol::lib::base, sol::lib::package);
	game_state.script_file(_config_filepath);

	LuaGameObjectFactory gof(&game_state);
	auto x = gof.CreateList();
	   return 0;
}
