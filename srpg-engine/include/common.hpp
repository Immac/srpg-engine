#ifndef GAME_UTIL_HPP
#define GAME_UTIL_HPP
#include <map>
#include <string>
#include <vector>

namespace SrpgEngine {
namespace Framework {

using string = std::string;

template<class T>
	using Vector = std::vector<T>;
template<class Key, class Value>
	using Map = std::map<Key,Value>;

}
}

#endif // GAME_UTIL_HPP
