#ifndef SRPG_ACTION_HPP
#define SRPG_ACTION_HPP
#include <gameobject.hpp>
#include <list>

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

struct TargetOption2 {
	bool active = false;
	Collection<string> Tags;
	explicit operator bool() {
		return active;
	}
};


struct ActionTargetOptions {
	ActionTargetOptions() = default;
	ActionTargetOptions(GameObject *action);
	TargetOption exclude;
	TargetOption2 excludes;
	TargetOption can_only_target;
	TargetOption targets_position;
	TargetOption direct_object;
};

class Action {
private:
	const Map<string,GameObject*>& world_;
	Collection<GameObject*> targets_;
	GameObject *subject_;
	GameObject *direct_object_;
	GameObject *what_;
	string action_;
	string function_name_;
	ActionTargetOptions options_;

	List<Position *> range_;
	string range_finder_path_ = "resources/scripts/mechanics/movement.lua";
public:
	Action(GameObject &event,Map<string,GameObject*>& world);
	List<Position *> Range() const {
		return range_;
	}
	Collection<GameObject*> &Targets(){
		return targets_;
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
