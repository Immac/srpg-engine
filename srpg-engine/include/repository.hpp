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

	T& operator[](string key)
	{
		return this->_map[key];
	}

	T& operator[](string key) const
	{
		return this->_map[key];
	}

	auto begin()
	{
		return _map.begin();
	}

	auto end()
	{
		return _map.end();
	}

	bool HasAny(string key)
	{
		return _map.find(key) != _map.end();
	}

private:
	Map<string,T> _map;

};
}
}


#endif // REPOSITORY_H
