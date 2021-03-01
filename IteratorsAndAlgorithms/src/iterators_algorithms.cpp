#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <forward_list>
#include <set>
#include <algorithm>


void myIteratorPrint(const int element)
{
	std::cout << element << std::endl;
}

int main()
{
	std::cout << "Hello Iteratos and Algorithms" << std::endl;
	std::cin.get();

//#define _ITERATORS_

#ifdef _ITERATORS_
	/*
	 * Iterators
	 */
	
	// 1. Random Access Iterator: vector, deque, array, random access refers to accessing elements in a container in an arbitrary order
	std::vector<int>::iterator vec_itr;
	auto vec_itr1 = vec_itr + 5;
	auto vec_itr2 = vec_itr - 4;
	if (vec_itr2 > vec_itr)
	{
		++vec_itr1;		// faster than itr++, itr++ returns a copied value
		--vec_itr2;
	}

	// 2. Bidirectional Iterator: list, set/multiset, map/multimap
	std::list<int>::iterator list_itr;
	++list_itr;
	--list_itr;
	std::advance(list_itr, 5);		// works but probably dangerous
									// list_itr += 5; can not be compiled

	auto list_itr2 = list_itr ++;	// list_itr doesn't change, return copy
	std::distance(list_itr, list_itr2);		// works
											// list_itr2 - list_itr; can not be compiled

	// 3. Forwrad Iterator: 
	std::forward_list<int>::iterator flist_itr;
	++flist_itr;
						// --flist_itr; can't be compiled

	// Unordered containers provide "at least" forwrad iteratros, can also provide bidirectional iterator, depends on implementation of stl

	// 4. Input Iterator: read and process values while iterating forward, random access/bidirectional/forward iterators are also valid input iterators
	// http://www.cplusplus.com/reference/iterator/InputIterator/
	int x_vec = *vec_itr;
	int x_list = *list_itr;
	int x_flist = *flist_itr;

	// 5. Output Iterator: output values while iterating forward, random access/bidirectional/forward iteratros that are not constant are also valid ouptut iterators
	// http://www.cplusplus.com/reference/iterator/OutputIterator/
	*vec_itr = 100;
	*list_itr = 100;
	*flist_itr = 100;
	std::vector<int>::const_iterator vec_citr;
													// *vec_citr = 100; can not be compiled

	std::set<int>::const_iterator set_citr;
	std::set<int> set = { 2,4,6,1,9 };

	for ( set_citr = set.cbegin(); set_citr != set.cend(); ++set_citr)
	{
		myIteratorPrint(*set_citr);
	}

	std::for_each(set.cbegin(), set.cend(), myIteratorPrint); // In std::for_each the function should work directly on the elment pointed by the iterator
#endif // _ITERATROS_

#define _ITERATOR_ADAPTOR_

#ifdef _ITERATOR_ADAPTOR_
	/*
	 * Iterator Adaptor (Predefined Iterator)
	 * 1. Insert iterator
	 * 2. Stream iterator
	 * 3. Reverse iterator
	 * 4. Move iterator (C++11)
	 */
	
	// 1. Insert Iterator
	std::vector<int> vec1 = { 4, 5 };
	std::vector<int> vec2 = { 12, 14, 16, 18 };
	std::vector<int>::iterator vec_itr = std::find(vec2.begin(), vec2.end(), 16);
	std::insert_iterator<std::vector<int>> vec_ins_itr(vec2, vec_itr);

	std::copy(vec1.begin(), vec1.end(),		// source
			  vec_ins_itr);					// destination
			  // vec2: {12, 14, 16, 18}
	// Othe insert interators: back_insert_iterator, front_insert_iterator
	std::front_insert_iterator<std::vector<int>> vec_front_ins_itr(vec2);

	// 2. Stream Iterator: stream iterator is to iterate through the data to and from a stream
	// TBD https://www.youtube.com/watch?v=vO2AlrBf5rQ&list=PL5jc9xFGsL8G3y3ywuFSvOuNm3GjBwdkb&index=7&t=591s


#endif // _ITERATOR_ADAPTOR_


}