#include "action.hpp"
#include <sol.hpp>
#include <iostream>

using namespace SrpgEngine;
using namespace Game;


Action::Action(GameObject& event, Map<string, GameObject*>& world)
	:world_(world)
{
	subject_ = event.Properties["subject"];
	type_ = subject_->Properties["listener"]
			->Dictionary["type"];
	sol::state lua;
	string path = "resources/scripts/mechanics/movement.lua";
	lua.open_libraries(sol::lib::base, sol::lib::package);
	auto result = lua.do_file(path);
	if(result.valid()){
		lua["pawn"] = lua.create_table_with(
						  "x",1,
						  "y",1,
						  "facing","north",
						  "has_moved",true);
		lua.do_string("answer = pawn_movement(pawn)");

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
