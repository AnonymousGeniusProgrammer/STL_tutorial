#include <vector>
#include <deque>
#include <list>
#include <array>
#include <iostream>
#include <iterator>

#define _DEQUE
#define _VECTOR
#define _LIST
#define _FLIST
#define _ARRAYCONTAINER

int main() {

#ifdef _VECTOR

	/*
	 * Vector
	 * fast insert/remove at the end;
	 */

	std::vector<int> vec;	// vec.size() == 0
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);	// vec: {4,1,8};	vec.size() == 3

	// vector specific operations:
	std::cout << "Random access without range check: " << vec[2] << std::endl;		// 8 (no range check)
	std::cout << "Random access with range check: " << vec.at(2) << std::endl;	// 8 (throw range_error exception of out of range

	// random access
	std::cout << "Random access of vec: ";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	// iterator access
	std::cout << "Iterator access of vec: ";
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	// c++11 access
	std::cout << "C++11 access of vec: ";
	for (auto it : vec)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	// Vector is a dynamically allocated contiguous array in memory
	int* p = &vec[0];
	p[2] = 6;

	// Common member functions of all cotainers.

	if (!vec.empty()) { std::cout << "vec is not empty" << std::endl; std::cout << "Size of vector is:" << vec.size() << std::endl; }

	std::vector<int> vec2(vec); // Copy constructor, vec2: {4, 1, 8}

	vec.clear(); // Remove all iterms in vec; vec.size() == 0

	vec2.swap(vec); // vec2 becomes empty, and vec has 3 items.

#endif // _VECTOR

#ifdef _DEQUE

	/*
	 * Deque
	 * fast insert/remove at the beginning and th end;
	 */
	std::deque<int> deq = { 4, 6, 7 };
	deq.push_front(2);	// deq: {2, 4, 6, 7}
	deq.push_back(3);	// deq: {2, 4, 6, 7, 3}

	// Deque has similar interface with vector
	// random access

	std::cout << "Random access of deque: "
		<< deq[1] << std::endl;

#endif // _DEQUE

#ifdef _LIST

	std::list<int> list = { 5, 2,9 };
	list.push_back(6); // list: {5, 2, 9, 6}
	list.push_front(4); // list: {4, 5, 2, 9, 6}

	std::list<int>::iterator itr = find(list.begin(), list.end(), 2); // *itr := 2

	std::cout << "After find function call of finding 2 in list, Iterator is pointing to: " << *itr << std::endl;

	list.insert(itr, 8);		// list: {4, 5, 8, 2, 9, 6}
								// return a iterator point to the first of the newly inserted elements
								// but it doesn't change the itr , *itr := 2

	std::cout << "list: ";
	for (auto it : list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	std::cout << "After inserting, iterator it is still pointing to: " << *itr << std::endl;

	itr++;						// *itr := 9

	std::cout << "After shifting to right by one, Iterator is now pointer at: " << *itr << std::endl;

	itr = list.erase(itr);		// list: {4, 5, 8, 2, 6}
								// return a interator point to the elment that follows the last element
								// erased by the function call

	std::cout << "After removing 9, list: ";
	for (auto it : list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	std::cout << "The erase function returns the iterator pointing at elment that follows the last element \'9\' erased by the function call, and it should point to: " << *itr << " (6)" << std::endl;

	std::list<int> list2 = { 6, 7, 7, 7, 6 };

	std::cout << "Now introducing list2: ";
	for (auto it : list2)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	std::list<int>::iterator itr_a = list2.begin();
	std::list<int>::iterator itr_b = list2.end();

	itr_a++;
	itr_b--;

	// cut the data from itr_a to itr_b in list2 and copy them into list at the position of itr
	list.splice(itr, list2, itr_a, itr_b);		 // list2: {6, 6}
												 // list1: {4, 5, 8, 6, 6, 6, 2, 6}
	std::cout << "After cutting operation, list: ";
	for (auto it : list)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	std::cout << "After cutting operation, list2: ";
	for (auto it : list2)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

#endif // _LIST

#ifdef _FLIST
	// Tbd
#endif // _FLIST

#ifdef _ARRAYCONTAINER

	int a[3] = { 3, 4, 5 };		// a.begin() not exist
	std::array<int, 3> array1 = { 3, 4, 5 }; 
	std::cout << "First element of Array container: " << *array1.begin() << std::endl;
								// a.end()
								// a.size()
								// a.swap()
	// draw back, the size can not be changed, it is different type to array1
	std::array<int, 4> arry2 = { 3, 4, 5, 6 };



#endif // _ARRAYCONTAINER


	std::cin.get();
}

