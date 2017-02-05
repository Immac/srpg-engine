#define SOL_USING_CXX_LUA 1
#include <luautil.hpp>
#include <iostream>
//#include <sol.hpp>

int main(){
	lua_State* L = luaL_newstate();

	   luaL_dostring(L, "a = 10 + 5");
	   lua_getglobal(L, "a");
	   int i = lua_tointeger(L, -1);
	   printf("%d\n", i);

	   lua_close(L);

	   return 0;
}
