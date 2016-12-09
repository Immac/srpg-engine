#include "s2dge-gamesystem.hpp"

void SrpgEngine::S2dge::Simple2DGraphicsEngine::Initialize()
{
	auto videomode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(videomode, "SFML works!");
}

void SrpgEngine::S2dge::Simple2DGraphicsEngine::Update()
{
	this->window->clear(sf::Color::Black);
	this->window->setFramerateLimit(60);

	sf::Event event;

	while (window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			window->close();
	}

	sf::RectangleShape sp;
	window->clear(sf::Color::Black);
	for(auto pair : this->GameObjects)
	{
		auto obj = pair.second;
		int cx = obj->Properties["position"]->Statistics["x"];
		int cy = obj->Properties["position"]->Statistics["y"];
		auto dx = obj->Properties["destination"]->Statistics["x"];
		auto dy = obj->Properties["destination"]->Statistics["y"];
		int sx = obj->Properties["speed"]->Statistics["x"];
		int sy = obj->Properties["speed"]->Statistics["y"];
		obj->Properties["position"]->Statistics["x"] = cx < dy ? cx + sx : cx;
		obj->Properties["position"]->Statistics["y"] = cy < dy ? cy + sy : cy;

		sp.setFillColor(sf::Color((unsigned)obj->Statistics["argb"]));
		sp.setPosition(obj->Properties["position"]->Statistics["x"],obj->Properties["position"]->Statistics["y"]);
		sp.setSize(sf::Vector2f(obj->Statistics["width"],obj->Statistics["height"]));

		window->draw(sp);
	}
	this->window->display();
}

SrpgEngine::Framework::string SrpgEngine::S2dge::Simple2DGraphicsEngine::GetSystemCode()
{
	return S2dge::SystemName;
}
