#include "luautil.hpp"
using namespace SrpgEngine;
using namespace Framework;
using namespace Lua;
using namespace Game;

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

Collection<string> LuaGameObjectFactory::getPropertyNames(sol::table object)
{
	sol::table properties_table = object["Properties"];
	if(!properties_table)
		return Collection<string>();
	return BuildVector<string>(properties_table);
}

Collection<string> LuaGameObjectFactory::getTags(sol::table object)
{
	sol::table tags_table = object["Tags"];
	if(!tags_table)


		return Collection<string>();

	return BuildVector<string>(tags_table);
}

Set<string> LuaGameObjectFactory::getSystems(sol::table object)
{
	sol::table systems_table = object["Systems"];
	if(!systems_table)
		return Set<string>();

	return BuildSet<string>(systems_table);
}

Vector<GameObject *> LuaGameObjectFactory::CreateList()
{
	auto root = (*sol_state_)["Root"];
	std::set<GameObject *,GameObjectComparator> game_objects;

	for(int i = 1; root[i] ; i++)
	{
		auto game_object = new GameObject();
		game_object->Systems = getSystems(root[i]);
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
		bool exists = game_object_iterator != game_objects.end(); // Should exist
		if(!exists)
		{
			throw "Object does not exits";// TODO: specify what object;
		}
		GameObject *game_object = *game_object_iterator;
		sol::table properties = (root[i])["Properties"];

		if(properties)
		{
			auto rep = BuildRepository<string>(properties);
			for(auto pair : rep)
			{
				string property_name = pair.first;
				string property_id = pair.second;
				game_object_dummy.Name = property_id;
				auto property = *game_objects.find(&game_object_dummy);
				game_object->Properties[property_name] = property;
			}
		}
	}

	return Vector<GameObject *>(game_objects.begin(),game_objects.end());
}

GameObject LuaGameObjectFactory::Create()
{
	throw "Not Yet Implemented";
	return GameObject();
}

