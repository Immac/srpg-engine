#include "scene.hpp"
using namespace SrpgEngine;
using namespace Game;

Act::Act(Vector<GameObject*> actors)
	:actors_(actors)
{

}


void Scene::HandleEvent(GameObject& event)
{
	context_.HandleEvent(event);
}
