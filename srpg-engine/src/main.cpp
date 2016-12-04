#include <iostream>
#include "lua.hpp"
#include "systemgeneral.hpp"


using namespace std;

int main(int argc, char *argv[])
{
   lua_State *S = luaL_newstate();
   luaL_openlibs(S);
   luaL_loadfile(S,"main.lua");
   lua_call(S,0,0);

   return 0;
}

