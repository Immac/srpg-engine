#include "event-handler.hpp"

EventHandler::EventHandler(Core &core, sf::Window &window)
{
	this->_core = &core;
	this->_window = &window;
}

void EventHandler::Handle(sf::Event &event)
{
			if (event.type == sf::Event::Closed)
			{
				_window->close();
			}

			if(event.type == sf::Event::KeyPressed)
			{

				switch (event.key.code) {
				case sf::Keyboard::L:
					{
						_core->HandleEvent(new GameObject("UpdateLayers"));
					}
					break;
				case sf::Keyboard::Q:
					{
						_core->HandleEvent(new GameObject("SetSelectedCoordinate"));
					}
					break;
				case sf::Keyboard::W:
					{
						_core->HandleEvent(new GameObject("DeselectAll"));
					}
					break;
				case sf::Keyboard::Escape:
					{
						_window->close();
					}
					break;
				case sf::Keyboard::Up:
					{
						_core->Controllers[0]->DigitalInputs["DigitalUp"] = true;
					}
					break;
				case sf::Keyboard::Down:
					{
						_core->Controllers[0]->DigitalInputs["DigitalDown"] = true;
					}
					break;
				case sf::Keyboard::Left:
					{
						_core->Controllers[0]->DigitalInputs["DigitalLeft"] = true;
					}
					break;
				case sf::Keyboard::Right:
					{
						_core->Controllers[0]->DigitalInputs["DigitalRight"] = true;
					}
					break;
				case sf::Keyboard::A:
					{
						_core->Controllers[0]->DigitalInputs["ButtonA"] = true;
					}
					break;
				case sf::Keyboard::Z:
					{
						_core->Controllers[0]->DigitalInputs["ButtonB"] = true;
					}
					break;
				}
			}
			else if(event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code) {
				case sf::Keyboard::Up:
					{
						_core->Controllers[0]->DigitalInputs["DigitalUp"] = false;
					}
					break;
				case sf::Keyboard::Down:
					{
						_core->Controllers[0]->DigitalInputs["DigitalDown"] = false;
					}
					break;
				case sf::Keyboard::Left:
					{
						_core->Controllers[0]->DigitalInputs["DigitalLeft"] = false;
					}
					break;
				case sf::Keyboard::Right:
					{
						_core->Controllers[0]->DigitalInputs["DigitalRight"] = false;
					}
					break;
				case sf::Keyboard::A:

					{
						_core->Controllers[0]->DigitalInputs["ButtonA"] = false;
					}
					break;
				case sf::Keyboard::Z:
					{
						_core->Controllers[0]->DigitalInputs["ButtonB"] = false;
					}
					break;
				}
			}
		}
