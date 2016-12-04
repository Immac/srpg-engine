#include <iostream>
#include <gameobject.hpp>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "Hello World!" << endl;
	auto gO = new SrpgEngine::Game::GameObject();
	gO->Name = "Hello";
	cout << gO->Name;
	return 0;
}
