#include "event-handler.hpp"
#include <game-controller.hpp>

void EventHandler::SendPressInputEvent(const string &input_name, int controller)
{
	GameObject event_object("input_pressed");
	event_object.Dictionary["input"] = input_name;
	event_object.Statistics["controller"] = controller;
	_core->HandleEvent(event_object);
}

void EventHandler::SendReleaseInputEvent(const string &input_name, int controller)
{
	GameObject event_object("input_released");
	event_object.Dictionary["input"] = input_name;
	event_object.Statistics["controller"] = controller;
	_core->HandleEvent(event_object);
}

EventHandler::EventHandler(Core &core, sf::Window &window)
{
	_core = &core;
	_window = &window;
}

void EventHandler::Handle(sf::Event &event)
{
			if (event.type == sf::Event::Closed) {
				_window->close();
			}

			if(event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::L: {
						GameObject event_object("UpdateLayers");
						_core->HandleEvent(event_object);
					} break;
				case sf::Keyboard::Escape: {
						_window->close();
					} break;
				case sf::Keyboard::Up: {
						SendPressInputEvent("DigitalUp",0);
					} break;
				case sf::Keyboard::Down: {
						SendPressInputEvent("DigitalDown",0);
					} break;
				case sf::Keyboard::Left: {
						SendPressInputEvent("DigitalLeft",0);
					} break;
				case sf::Keyboard::Right: {
						SendPressInputEvent("DigitalRight",0);
					} break;
				case sf::Keyboard::A: {
						SendPressInputEvent("ButtonA",0);
					} break;
				case sf::Keyboard::Z: {
						SendPressInputEvent("ButtonB",0);
					} break;
				}
			} else if(event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::Up: {
						SendReleaseInputEvent("DigitalUp",0);
					} break;
				case sf::Keyboard::Down: {
						SendReleaseInputEvent("DigitalDown",0);
					} break;
				case sf::Keyboard::Left: {
						SendReleaseInputEvent("DigitalLeft",0);
					} break;
				case sf::Keyboard::Right: {
						SendReleaseInputEvent("DigitalRight",0);
					} break;
				case sf::Keyboard::A: {
						SendReleaseInputEvent("ButtonA",0);
					} break;
				case sf::Keyboard::Z: {
						SendReleaseInputEvent("ButtonB",0);
					} break;
				}
			}
		}
