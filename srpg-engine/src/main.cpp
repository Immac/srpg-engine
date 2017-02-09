#define SOL_USING_CXX_LUA 1
#include <luautil.hpp>
#include <iostream>
#include <sol.hpp>

int main(){
	sol::state lua;
		   lua.open_libraries(sol::lib::base, sol::lib::coroutine, sol::lib::string, sol::lib::io );

		   lua.script( "print('bark bark bark!')" );
	   return 0;
}
