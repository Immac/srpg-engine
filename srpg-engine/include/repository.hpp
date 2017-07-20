#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "common.hpp"

namespace SrpgEngine {
namespace Framework {

template <class TEntity>
class Repository
{
public:
	Repository() = default;

	TEntity& operator[](string key)
	{
		return this->_map[key];
	}

	TEntity& operator[](string key) const
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

	bool HasKey(string key)
	{
		return _map.find(key) != _map.end();
	}

private:
	Map<string,TEntity> _map;
};

}
}


#endif // REPOSITORY_H
