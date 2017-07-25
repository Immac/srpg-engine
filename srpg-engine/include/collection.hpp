#ifndef COLLECTION_HPP
#define COLLECTION_HPP
#include <vector>
#include <algorithm>

namespace Utilities {

template <class T>
class Collection
{
private:
	std::vector<T> container_;
public:
	Collection() = default;

	T& operator[](int index)
	{
		return this->container_[index];
	}

	T& operator[](int index) const
	{
		return this->container_[index];
	}

	auto begin()
	{
		return container_.begin();
	}

	auto begin() const
	{
		return container_.begin();
	}

	auto end()
	{
		return container_.end();
	}

	auto end() const
	{
		return container_.end();
	}

	void Add(const T& item){
		container_.push_back(item);
	}

	bool Has(const T& item) {
		return std::find(container_.begin(),container_.end(),item) != container_.end();
	}

	bool HasAny(const Collection<T>& item_collection) {
		for(const auto& item : item_collection) {
			if(this->Has(item)) {
				return true;
			}
		}
		return false;
	}

};

}

#endif // COLLECTION_HPP