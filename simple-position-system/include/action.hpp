#ifndef SRPG_ACTION_HPP
#define SRPG_ACTION_HPP
#include <gameobject.hpp>

namespace SrpgEngine {
namespace Game {
class Position {
public:
	int x;
	int y;
};

struct TargetOption {
	string tag;
	bool active;
	operator string(){
		return tag;
	}
	explicit operator bool(){
		return active;
	}
};

struct TargetingOptions {
	TargetingOptions() = default;
	TargetingOptions(GameObject *action);
	TargetOption ignore;
	TargetOption can_only_target;
	TargetOption targets_position;
	TargetOption direct_object;
};

class Action {
private:
	const Map<string,GameObject*>& world_;
	GameObject *subject_;
	GameObject *direct_object_;
	string action_;
	string function_name_;
	TargetingOptions options_;

	Vector<Position *> range_;
	string range_finder_path_ = "resources/scripts/mechanics/movement.lua";
public:
	Action(GameObject &event,Map<string,GameObject*>& world);
	Vector<Position *> Range() const {
		return range_;
	}
	bool SetTarget(GameObject& target);
	bool SetTarget(Position& position);
	void EvaluateTargets(Map<string, GameObject*> world);
	bool ExecuteAction();
	GameObject* DirectObject() const;
};

}
}

#endif // SRPG_ACTION_HPP
