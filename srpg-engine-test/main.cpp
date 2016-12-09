#include <iostream>
#include <gameobject.hpp>
#include <gamecore.hpp>
#include <s2dge-factory.hpp>
#include <s2dge-gamesystem.hpp>

int main(){
	SrpgEngine::Game::Core core;

	SrpgEngine::S2dge::DrawableTestObjectFactory factory;
	auto item = factory.Create();

	SrpgEngine::Game::GameSystem *s2dge = new SrpgEngine::S2dge::Simple2DGraphicsEngine();
	s2dge->Initialize();

	core.Objects["item"] = &item;
	core.Systems[s2dge->GetSystemCode()] = s2dge;
	core.Run();
	return 0;
}

//using string = std::string;
//using namespace SrpgEngine::Framework;
//using namespace SrpgEngine::Game;

//GameObject *makeTile(string name,int cost,int y, int x);
//GameObject *makeMovable(string name, int movement, int y, int x);

//static int ScreenWidth = 600;
//static int ScreenHeight = 600;

//int main()
//{
//	GameObject world;
//	for(int i = 0; i < 3; i++)
//	{
//		for(int j = 0; j < 3; j++)
//		{
//			if(i == 1)
//			{
//				world.Objects.push_back(makeTile("water",2,i,j));
//			}
//			else
//			{
//				world.Objects.push_back(makeTile("grass",1,i,j));
//			}
//		}
//	}
//	GameObject *actor = makeMovable("actor",2,0,0);

//	Vector<sf::RectangleShape*> rects;
//	for(GameObject *go : world.Objects)
//	{
//		auto rect = new sf::RectangleShape(sf::Vector2f(100,100
//														));
//		rect->setFillColor(!go->Name.compare("water")
//						   ? sf::Color::Blue
//						   : sf::Color::Green);
//		rect->setPosition( sf::Vector2f(go->Statistics.Get("x")*100,
//										go->Statistics.Get("y")*100));
//		rects.push_back(rect);
//	}

//	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "SFML works!");

//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		if(sf::Keyboard::R)
//			actor->Statistics.Set("move",2);
//		if(sf::Keyboard::Right)
//		{

//		}
//		window.clear();
//		for(auto rect :  rects)
//		{
//			auto c = rect->getFillColor();
//			window.draw(*rect);
//		}
//		window.display();
//	}

//	return 0;
//}

//GameObject *makeTile(string name, int cost, int y, int x)
//{
//	GameObject *tile = new GameObject();
//	tile->Name = name;
//	tile->Statistics.Add("cost",cost);
//	tile->Statistics.Add("y",y);
//	tile->Statistics.Add("x",x);
//	return tile;
//}

//GameObject *makeMovable(string name, int movement, int y, int x)
//{
//	GameObject *movable = new GameObject();
//	movable->Name = name;
//	movable->Statistics.Add("move",2);
//	movable->Statistics.Add("y",y);
//	movable->Statistics.Add("x",x);
//	return movable;
//}
