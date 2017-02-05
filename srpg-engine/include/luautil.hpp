#ifndef SRPG_LUA_UTIL_HPP
#define SRPG_LUA_UTIL_HPP
#include <lua.hpp>
#include <common.hpp>
#include <iostream>

namespace SrpgEngine {
namespace Framework {
namespace Lua {


class LuaScript {
public:
	LuaScript(const std::string& _filename);
	~LuaScript();
	void PrintError(const std::string& variableName, const std::string& reason);
	std::vector<int> GetIntVector(const std::string& name);
	std::vector<std::string> GetTableKeys(const std::string& name);

	inline void Clean() {
	  int n = lua_gettop(_state);
	  lua_pop(_state, n);
	}

	template<typename T>
	T get(const std::string& variableName) {
	  if(!_state) {
		PrintError(variableName, "Script is not loaded");
		return luaGetdefault<T>();
	  }

	  T result;
	  if(lua_gettostack(variableName)) { // variable succesfully on top of stack
		result = luaGet<T>(variableName);
	  } else {
		result = luaGetdefault<T>();
	  }


	  Clean();
	  return result;
	}

	bool lua_gettostack(const std::string& variableName) {
	  _level = 0;
	  std::string var = "";
		for(unsigned int i = 0; i < variableName.size(); i++) {
		  if(variableName.at(i) == '.') {
			if(_level == 0) {
			  lua_getglobal(_state, var.c_str());
			} else {
			  lua_getfield(_state, -1, var.c_str());
			}

			if(lua_isnil(_state, -1)) {
			  PrintError(variableName, var + " is not defined");
			  return false;
			} else {
			  var = "";
			  _level++;
			}
		  } else {
			var += variableName.at(i);
		  }
		}
		if(_level == 0) {
		  lua_getglobal(_state, var.c_str());
		} else {
		  lua_getfield(_state, -1, var.c_str());
		}
		if(lua_isnil(_state, -1)) {
			PrintError(variableName, var + " is not defined");
			return false;
		}

		return true;
	}

	// Generic get
	template<typename T>
	T luaGet(const std::string& variableName) {
	  return 0;
	}

	template<typename T>
	T luaGetdefault() {
	  return 0;
	}

private:
	lua_State* _state;
	std::string _filename;
	int _level;
};

 // Specializations

template <>
inline bool LuaScript::luaGet<bool>(const std::string& variableName) {
	return (bool)lua_toboolean(_state, -1);
}

template <>
inline float LuaScript::luaGet<float>(const std::string& variableName) {
	if(!lua_isnumber(_state, -1)) {
	  PrintError(variableName, "Not a number");
	}
	return (float)lua_tonumber(_state, -1);
}

template <>
inline int LuaScript::luaGet<int>(const std::string& variableName) {
	if(!lua_isnumber(_state, -1)) {
	  PrintError(variableName, "Not a number");
	}
	return (int)lua_tonumber(_state, -1);
}

template <>
inline std::string LuaScript::luaGet<std::string>(const std::string& variableName) {
	std::string s = "null";
	if(lua_isstring(_state, -1)) {
	  s = std::string(lua_tostring(_state, -1));
	} else {
	  PrintError(variableName, "Not a string");
	}
	return s;
}

template<>
inline std::string LuaScript::luaGetdefault<std::string>() {
  return "null";
}



}
}
}

#endif // SRPG_LUA_UTIL_HPP
