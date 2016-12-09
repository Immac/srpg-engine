#ifndef GAME_UTIL_HPP
#define GAME_UTIL_HPP
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>

namespace SrpgEngine {
namespace Framework {

using string = std::string;
template<class T>
	using Set = std::set<T>;
template<class T>
	using Vector = std::vector<T>;
template<class Key, class Value>
	using Map = std::map<Key,Value>;
template<class Key, class Value>
	using UnorderedMap = std::unordered_map<Key,Value>;
template<class Key, class Value>
	using MultiMap = std::multimap<Key,Value>;
template<class Key, class Value>
	using UnorderedMultiMap = std::unordered_multimap<Key,Value>;
}

namespace Util {
template<class T>
	using Set = std::set<T>;

template <class T>
static bool Find(Set<T> set, T item){
	auto result = set.find(item);
	return result == set.end();
}

}

}

#endif // GAME_UTIL_HPP
