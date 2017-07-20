#include "action.hpp"
#include <sol.hpp>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace SrpgEngine;
using namespace Game;


GameObject* Action::DirectObject() const
{
	return direct_object_;
}

Action::Action(GameObject& event, Map<string, GameObject*>& world)
	:world_(world)
{
	action_ = event.Dictionary["action"];
	subject_ = event.Properties["subject"];
	const auto action = subject_
						->Properties["actions"]
						->Properties[action_];
	options_ = TargetingOptions(action);
	auto range = action->Dictionary["range"];

	std::transform(range.begin(), range.end(), range.begin(), ::tolower);
	sol::state lua;

	lua.open_libraries(sol::lib::base, sol::lib::package);
	auto result = lua.do_file(range_finder_path_);
	if(result.valid()) {
		lua["piece"] = lua.create_table_with(
						   "x",subject_->Statistics["x"],
				"y",subject_->Statistics["y"],
				"facing",subject_->Dictionary["facing"],
				"has_moved",static_cast<bool>(subject_->Statistics["has_moved"]));
		std::stringstream ss;
		ss << "answer = " << range <<  "(piece)";
		lua.do_string(ss.str());

		for(int i = 1; lua["answer"][i] ; i++){
			auto l = new Position();
			l->x = lua["answer"][i]["x"];
			l->y = lua["answer"][i]["y"];
			range_.push_back(l);
		}
	} else {
		std::cout << "error opening script with path: "
				  << range_finder_path_ << std::endl;
	}
}

bool Action::SetTarget(GameObject& target)
{
	/// Check if target is valid, if not return false
	direct_object_ = &target;
	//NOT IMPLEMENTED YET
	std::cout << "SetTarget(GameObject& target) not implemented" << std::endl;
}

bool Action::SetTarget(Position& position)
{
	auto iter = std::find_if(range_.begin(),range_.end(),[&position](auto pos){
		return pos->x == position.x && pos->y == position.y;
	});
	if (iter == range_.end()){
		return false;
	}
	if(options_.direct_object.tag == "self") {
		direct_object_ = subject_;
		direct_object_->Statistics["x"] = position.x;
		direct_object_->Statistics["y"] = position.y;
	}
	return true;
}


void Action::EvaluateTargets(Map<string,GameObject*> world)
{
	Vector<GameObject *> targets;
	if(options_.ignore) {
		for(const auto& record : world){
			const auto& object = record.second;
			if(object->Statistics.HasKey("x")
			   && object->Statistics.HasKey("y")
			   && object->Statistics.HasKey("z")) {
				Util::RemoveIf(range_,[&object,this](auto position){
					return object->Statistics["x"] == position->x
							&& object->Statistics["y"] == position->y
							&& Util::HasAnyIterative(object->Tags,options_.ignore.tag);
				});
			}
		}
	}
	if(options_.can_only_target){
		for(const auto& record : world){
			const auto& object = record.second;
			if(object->Statistics.HasKey("x")
			   && object->Statistics.HasKey("y")
			   && object->Statistics.HasKey("z")) {

				Util::RemoveIf(range_,[&object,this](auto position){
					return object->Statistics["x"] == position->x
							&& object->Statistics["y"] == position->y
							&& !Util::HasAnyIterative(object->Tags,options_.can_only_target.tag);
				});
			}
		}
	}
}

bool Action::ExecuteAction()
{

}

TargetingOptions::TargetingOptions(GameObject* action)
{
	ignore.active = static_cast<bool>(action->Statistics["exclude_specific"]);
	ignore.tag = action->Dictionary["target_exclude"];
	can_only_target.active = static_cast<bool>(action->Statistics["target_specific"]);
	can_only_target.tag = action->Dictionary["target_type"];
	targets_position.active = static_cast<bool>(action->Statistics["targets_position"]);
	direct_object.tag = action->Dictionary["direct_object"];
	direct_object.active = true;
}
