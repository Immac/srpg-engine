#include "scene.hpp"
using namespace SrpgEngine;
using namespace Game;

Act::Act(Vector<GameObject*> actors)
	:actors_(actors)
{

}


void Scene::HandleEvent(GameObject& event)
{
	auto iter = Util::First(event.Tags,[](auto& tag){return tag == "push_scene";});
	if(iter != nullptr){

	}
	context_.HandleEvent(event);
}
