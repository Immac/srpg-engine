#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP
#include <gamecore.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

using namespace SrpgEngine::Game;

class EventHandler{
private:
	Core *_core;
	sf::Window *_window;
public:
	EventHandler(Core &core,sf::Window &window);

	void Handle(sf::Event &event);
};

#endif // EVENT_HANDLER_HPP
