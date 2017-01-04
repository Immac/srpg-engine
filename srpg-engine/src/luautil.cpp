#include "luautil.hpp"
using namespace SrpgEngine::Framework::Lua;

LuaScript::LuaScript(const std::string& filename) {
	_state = luaL_newstate();
	if (luaL_loadfile(_state, filename.c_str()) || lua_pcall(_state, 0, 0, 0)) {
		std::cout<<"Error: failed to load ("<<filename<<")"<<std::endl;
		_state = 0;
	}

	if(_state) luaL_openlibs(_state);
}

LuaScript::~LuaScript() {
	if(_state) lua_close(_state);
}

void LuaScript::PrintError(const std::string& variableName, const std::string& reason) {
	std::cout<<"Error: can't get ["<<variableName<<"]. "<<reason<<std::endl;
}

std::vector<int> LuaScript::GetIntVector(const std::string& name) {
	std::vector<int> v;
	lua_gettostack(name.c_str());
	if(lua_isnil(_state, -1)) { // array is not found
		return std::vector<int>();
	}
	lua_pushnil(_state);
	while(lua_next(_state, -2)) {
		v.push_back((int)lua_tonumber(_state, -1));
		lua_pop(_state, 1);
	}
	Clean();
	return v;
}

std::vector<std::string> LuaScript::GetTableKeys(const std::string& name) {
	std::string code =
		"function getKeys(name) "
		"s = \"\""
		"for k, v in pairs(_G[name]) do "
		"    s = s..k..\",\" "
		"    end "
		"return s "
		"end"; // function for getting table keys
	luaL_loadstring(_state,
		code.c_str()); // execute code
	lua_pcall(_state,0,0,0);
	lua_getglobal(_state, "getKeys"); // get function
	lua_pushstring(_state, name.c_str());
	lua_pcall(_state, 1 , 1, 0); // execute function
	std::string test = lua_tostring(_state, -1);
	std::vector<std::string> strings;
	std::string temp = "";
	std::cout<<"TEMP:"<<test<<std::endl;
	for(unsigned int i = 0; i < test.size(); i++) {
		if(test.at(i) != ',') {
			temp += test.at(i);
		} else {
			strings.push_back(temp);
			temp= "";
		}
	}
	Clean();
	return strings;
}
