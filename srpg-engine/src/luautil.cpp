#include "luautil.hpp"

using namespace SrpgEngine::Framework::Lua;
using SrpgEngine::Framework::Lua::GameObject;
using SrpgEngine::Framework::Repository;
using SrpgEngine::Framework::Vector;
using SrpgEngine::Game::GameObjectComparator;

Repository<int> LuaGameObjectFactory::getStats(sol::table object)
{
	sol::table stats = object["Statistics"];
	if(!stats)
		return Repository<int>();

	Repository<int> repo = BuildRepository<int>(stats);
	return repo;
}

Repository<string> LuaGameObjectFactory::getDictionary(sol::table object)
{
	sol::table dictionary_table = object["Dictionary"];
	if(!dictionary_table)
		return Repository<string>();

	Repository<string> repo = BuildRepository<string>(dictionary_table);

	return repo;
}

Vector<string> LuaGameObjectFactory::getPropertyNames(sol::table object)
{
	sol::table properties_table = object["Properties"];
	if(!properties_table)
		return Vector<string>();

	return BuildVector<string>(properties_table);
}

Vector<string> LuaGameObjectFactory::getTags(sol::table object)
{
	sol::table tags_table = object["Tags"];
	if(!tags_table) return Vector<string>();
	Vector<string> vec = BuildVector<string>(tags_table);
	return vec;
}



Vector<GameObject *> LuaGameObjectFactory::CreateList()
{
	auto root = (*_state)["Root"];
	std::set<GameObject *,GameObjectComparator> game_objects;


	for(int i = 1; root[i] ; i++)
	{
		auto game_object = new GameObject();
		game_object->Statistics = getStats(root[i]);
		game_object->Dictionary = getDictionary(root[i]);
		game_object->Name = root[i]["Name"];
		game_object->Tags = getTags(root[i]);
		game_objects.insert(game_object);
	}
	GameObject game_object_dummy;
	for(int i = 1; root[i] ; i++)
	{
		game_object_dummy.Name = root[i]["Name"];
		auto game_object_iterator = game_objects.find(&game_object_dummy);
		bool exists = game_object_iterator != game_objects.end(); //Should exist
		if(!exists)
		{
			throw "Object does not exits";// TODO: specify what object;
		}
		GameObject *game_object = *game_object_iterator;
		auto property_names = getPropertyNames(root[i]);
		for(auto name : property_names)
		{
			game_object_dummy.Name = name;
			auto prop = *game_objects.find(&game_object_dummy);
			game_object->Properties.Add(name,prop);
			int a = 1;
		}
		int a = 1;
	}

	return Vector<GameObject *>(game_objects.begin(),game_objects.end());
}

GameObject LuaGameObjectFactory::Create()
{
	return GameObject();
}

