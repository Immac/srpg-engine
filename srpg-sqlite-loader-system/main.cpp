//#include <iostream>
//#include <luautil.hpp>

//using std::string;
//using SrpgEngine::Framework::Lua::LuaScript;

//struct Object {
//	Object *objects;
//};

//int main(int argc, char *argv[])
//{
//	LuaScript script("resources/game-database.lua");

//	return 0;
//}

//int example(int argc, char *argv[])
//{
//	LuaScript script("srpg-database.lua");
//	float posX = script.get<float>("player.position.x");
//	float posY = script.get<float>("player.position.y");
//	std::string filename = script.get<std::string>("player.filename");
//	int hp = script.get<int>("player.HP");

//	std::cout<<"Position X = "<<posX<<", Y = "<<posY<<std::endl;
//	std::cout<<"Filename:"<<filename<<std::endl;
//	std::cout<<"HP:"<<hp<<std::endl;

//	// getting arrays

//	std::vector<int> v = script.GetIntVector("array");
//	std::cout<<"Contents of array:";
//	for(std::vector<int>::iterator it = v.begin();
//		it != v.end();
//		it++) {
//		std::cout<<*it<<",";
//	}
//	std::cout<<std::endl;

//	// getting table keys:
//	std::vector<std::string> keys = script.GetTableKeys("player");
//	std::cout<<"Keys of [player] table:";
//	for(std::vector<std::string>::iterator it = keys.begin();
//		it != keys.end();
//		it++) {
//		std::cout<<*it<<",";
//	}
//	std::cout<<std::endl;
//	return 0;
//}
