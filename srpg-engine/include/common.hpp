#ifndef GAME_UTIL_HPP
#define GAME_UTIL_HPP
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

namespace SrpgEngine {
namespace Framework {

using string = std::string;
template<class T>
using Set = std::set<T>;
template<class T>
using Vector = std::vector<T>;
template<class Key, class Value> using Map = std::map<Key,Value>;
template<class Key, class Value> using MultiMap = std::multimap<Key,Value>;
using byte = uint8_t;

} // Framework

namespace Util {

using namespace Framework;

template <class TContainer,class TItem>
static bool HasAny(TContainer container, TItem item) {
	return container.find(item) != container.end();
}

template<class K, class V>
static Vector<V> ExtractValues(const Map<K,V>& map){
	Vector<V> output;
	 for (auto const& element : map) {
	   output.push_back(element.second);
	 }
	 return output;
}

template<class TContainer,class TFunction>
static void RemoveIf(TContainer &container,TFunction function){
	auto  from =
			std::remove_if(container.begin(),container.end(),function);
	container.erase(from,container.end());
}

template<class TContainer,class TItem>
static bool HasAnyIterative(const TContainer& container, TContainer item)
{
	return std::find(container.begin(),container.end(),item) != container.end();
}

template<class TContainer, class TFunction>
static auto First(const TContainer& container, TFunction predicate) {
	auto result = std::find_if(container.begin(),container.end(),predicate);
	return result;
}

template<class TContainer,class TFunction>
static void Sort(TContainer &container, TFunction function)
{
	std::sort(container.begin(), container.end(),function);
}

} // Util
} // SrpgEngine

#endif // GAME_UTIL_HPP
