#include <iostream>
#include <set>

using namespace std;

bool asd(std::string arg1,std::string arg2){
	return arg1.compare(arg2) < 0;
}

int main(int argc, char *argv[])
{
	std::set<std::string,bool(*)(std::string,std::string)> my_set(asd);
	my_set.insert("Alana");
	my_set.insert("Zeria");
	my_set.insert("Maria");
	my_set.insert("Val");
	my_set.insert("Meche");
	my_set.insert("Alana");
	for(auto i : my_set)
		cout << i << std::endl;
	return 0;
}

