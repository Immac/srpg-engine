#include <iostream>
#include <gameobject.hpp>
#include <SFML/Window.hpp>

using namespace std;
using GameObject = SrpgEngine::Game::GameObject;
//int main(int argc, char *argv[])
//{
//	cout << "Hello World!" << endl;
//	auto gameObject = new GameObject();
//	gameObject->Name = "Hello";

//	cout << gameObject->Name;
//	return 0;
//}

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
