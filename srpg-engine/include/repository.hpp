#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "common.hpp"

namespace SrpgEngine {
namespace Framework {

template <class T>
class Repository
{
public:
	Repository() = default;

	T Get(string key)
	{
		return _map[key];
	}

	void Add(string key,T value)
	{
		this->_map.insert(make_pair(key,value));
	}

	T Remove(string key)
	{
		this->_map.erase(key);
	}

private:
	Map<string,T> _map;
};
}
}


#endif // REPOSITORY_H
