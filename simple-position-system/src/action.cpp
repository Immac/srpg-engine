#include "action.hpp"
#include <sol.hpp>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace SrpgEngine;
using namespace Game;


Action::Action(GameObject& event, Map<string, GameObject*>& world)
	:world_(world)
{
	subject_ = event.Properties["subject"];
	function_name_ = subject_->Properties["movement"]
			->Dictionary["type"];
	std::transform(function_name_.begin(), function_name_.end(), function_name_.begin(), ::tolower);
	function_name_.append("_range");
	sol::state lua;
	string path = "resources/scripts/mechanics/movement.lua";
	lua.open_libraries(sol::lib::base, sol::lib::package);
	auto result = lua.do_file(path);
	if(result.valid()){
		lua["pawn"] = lua.create_table_with(
						  "x",4,
						  "y",4,
						  "facing","north",
						  "has_moved",true);
		std::stringstream ss;
		ss << "answer = " << function_name_ <<  "(pawn)";

		lua.do_string(ss.str());

		Vector<Position*> posible_targets;
		for(int i = 1; lua["answer"][i] ; i++){
			auto l = new Position();
			l->x = lua["answer"][i]["x"];
			l->y = lua["answer"][i]["y"];
			posible_targets.push_back(l);
		}
		int i = 0;
	} else {
		std::cout << "error opening script with path: "
				  << path << std::endl;
	}

//	sol::state unit;
//	struct {
//		int x = 1;
//		int y = 2;
//		string facing = "south";
//	} pawn;

//	const auto& asd = context["pawn_movement"](pawn);
	int i = 0;
}
