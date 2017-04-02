#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP
#include <gameobject.hpp>
#include <map>
#include <SFML/Window/Event.hpp>

using SrpgEngine::Game::GameObject;
using namespace SrpgEngine::Framework;
class SfmlEventObject;

namespace SfmlExample {
class EventHandler {
public:
	EventHandler();
	Vector<SfmlEventObject*> Events;
};

class SfmlEventObject : public GameObject {
private:
	sf::Event _event;
public:
	SfmlEventObject(sf::Event event);

	sf::Event GetEvent() const;
};
}

#endif // EVENT_HANDLER_HPP
