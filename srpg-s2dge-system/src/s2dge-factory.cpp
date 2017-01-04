#include "s2dge-factory.hpp"
#include "time.h"
#include <SFML/Graphics.hpp>

using namespace SrpgEngine;

S2dge::DrawableTestObjectFactory::DrawableTestObjectFactory()
{

	this->_randomEngine = new std::mt19937_64(time(0));
}

S2dge::DrawableTestObjectFactory::~DrawableTestObjectFactory()
{
	delete this->_randomEngine;
}

Game::GameObject S2dge::DrawableTestObjectFactory::Create()
{

	std::uniform_int_distribution<int> uniform_dist(100, 640);
	std::uniform_int_distribution<int> speed_dist(2, 20);
	std::uniform_int_distribution<int> color_dist(0xff000000, 0xffffffff);
	Game::GameObject object;
	object.Name = "test";
	object.Statistics["height"] = 64;
	object.Statistics["width"] = 64;
	object.Statistics["argb"] = color_dist(*_randomEngine);
	object.Statistics["textured"] = false;

	//
	auto property = new Game::GameObject();
	property->Name = "destination";
	property->Statistics["x"] = uniform_dist(*_randomEngine);
	property->Statistics["y"] = uniform_dist(*_randomEngine);
	object.Properties["destination"] = property;
	//
	property = new Game::GameObject();
	property->Name = "position";
	property->Statistics["x"] = 10;
	property->Statistics["y"] = 20;
	object.Properties["position"] = property;
	//
	property = new Game::GameObject();
	property->Name = "speed";
	property->Statistics["x"] = speed_dist(*_randomEngine);
	property->Statistics["y"] = speed_dist(*_randomEngine);
	object.Properties["speed"] = property;
	//
	property = new Game::GameObject();
	property->Name = "sprite";
	property->Statistics["width"] = 64;
	property->Statistics["height"] = 64;

	sf::Sprite *sprite = new sf::Sprite();
	sf::Texture *texture = new sf::Texture();
	if (!texture->loadFromFile("resources/grass.png")) throw 1;
	sprite->setTexture(*texture);
	property->Data["sprite"] = sprite;
	property->Data["texture"] = texture;
	object.Properties["sprite"] = property;
	object.Tags.push_back("S2DGE");

	object.Dictionary.Add("texture","none");
	if(!Util::Find<Framework::string>(object.Systems,"S2DGE")) {
		object.Systems.insert("S2DGE");
	}
	return object;
}
