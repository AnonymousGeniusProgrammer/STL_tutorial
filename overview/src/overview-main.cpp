//#include <stdlib.h>
//#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	/* 
	* Vector is dynamic array that can grow, it is dynamically allocated on the heap and the size of it is not fixed.
	* Each container should provide a iterator interface:
	* vector<int>::iterator std::vector::begin()/end()
	*/

	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);

	std::vector<int>::iterator itr1 = vec.begin();  // half-open:	[begin, end)
	std::vector<int>::iterator itr2 = vec.end();

	for (auto itr = itr1; itr != itr2; ++itr)
	{
		// Iterator is a individual class, but you can dereference it as using a pointer
		std::cout << *itr << " " << std::endl;
	}

	std::sort(itr1, itr2);

	for (auto itr = vec.begin(); itr != vec.end(); ++itr)
	{
		std::cout << *itr << " " << std::endl;
	}

	std::cin.get();
}