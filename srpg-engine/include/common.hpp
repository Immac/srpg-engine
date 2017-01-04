#ifndef GAME_UTIL_HPP
#define GAME_UTIL_HPP
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

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
using byte = uint8_t;

} // Framework

namespace Util {

using Framework::Set;
using Framework::Map;
using Framework::Vector;

template <class T>
static bool Find(Set<T> set, T item) {
	return set.find(item) != set.end();
}

template<class K,class V>
static bool Find(Map<K,V> map, K key) {
	return map.find(key) != map.end();
}

template<class T>
static bool Find(Vector<T> vector, T item)
{
	return std::find(vector.begin(),vector.end(),item) != vector.end();
}

} // Util
} // SrpgEngine

#endif // GAME_UTIL_HPP
