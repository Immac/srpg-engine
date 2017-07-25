#include "action.hpp"
#include <sol.hpp>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>

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
	options_ = ActionTargetOptions(action);
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
	return false;
}

bool Action::SetTarget(Position& position)
{
	//	auto iter = std::find_if(range_.begin(),range_.end(),[&position](auto pos){
	//		return pos->x == position.x && pos->y == position.y;
	//	});

	//	if (iter == range_.end()){
	//		return false;
	//	}
	std::cout << "SetTarget(Position& position) not implemented" << std::endl;
	return false;
}


void Action::EvaluateTargets(Map<string,GameObject*> world)
{	
	Collection<GameObject*> objects_in_range;
	for(const auto& record : world)	{
		const auto &object = record.second;
		for(const auto& position : range_) {
			if(object->Statistics.HasKey("x")
			   && object->Statistics.HasKey("y")
			   && object->Statistics.HasKey("z")
			   && object->Statistics["x"] == position->x
			   && object->Statistics["y"] == position->y) {
				objects_in_range.Add(object);
			}
		}
	}

	for(const auto& object : objects_in_range) {
		range_.remove_if([&object,this](auto position) {
			if(object->Statistics["x"] == position->x
			   && object->Statistics["y"] == position->y)
			{
				auto has_no_excluded_tags
						= !(options_.excludes
							&& object->Tags.HasAny(options_.excludes.Tags));
				auto has_required_tag
						= options_.can_only_target
						  ? object->Tags.Has(options_.can_only_target.tag)
						  : true;
				if(has_no_excluded_tags && has_required_tag) {
					targets_.Add(object);
				} else {
					return true;
				}
			}
			return false;
		});
	}
	return;
}

bool Action::ExecuteAction()
{	
	if(options_.direct_object.tag == "self") {
		direct_object_ = subject_;
		direct_object_->Statistics["x"] = 2;
		direct_object_->Statistics["y"] = 2;
	}
	return true;
}

ActionTargetOptions::ActionTargetOptions(GameObject* action)
{
	if(action->Tags.Has("exclude") && action->Properties.HasKey("exclude")) {
		excludes.active = true;
		for(const auto& tag : action->Properties["exclude"]->Tags) {
			excludes.Tags.Add(tag);
		}
	}

	exclude.active = static_cast<bool>(action->Statistics["exclude_specific"]);
	exclude.tag = action->Dictionary["target_exclude"];
	can_only_target.active = static_cast<bool>(action->Statistics["target_specific"]);
	can_only_target.tag = action->Dictionary["target_type"];
	targets_position.active = static_cast<bool>(action->Statistics["targets_position"]);
	direct_object.tag = action->Dictionary["direct_object"];
	direct_object.active = true;
}
