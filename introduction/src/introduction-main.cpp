// Introduction to templates

#include <iostream>

template<typename T>
T square(T x) {
	return x * x;
}

template<typename T>
class BoVector
{
	T _arr[1000];
	int _size;
public:
	BoVector() : _size(0) {}
	void push(T x) { _arr[_size] = x; _size++; }
	T get(int i) const { return _arr[i]; }
	int getSize() const { return _size; }
	void print() const { for (int i = 0; i < _size; i++) { std::cout << _arr[i] << std::endl; } }
};

template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, BoVector<T>& rhs2)
{
	BoVector<T> ret;
	for (int i = 0; i < rhs1.getSize(); i++) {
		ret.push(rhs1.get(i) * rhs2.get(i));
	}
	return ret;
}

int main() { 
	// Code bloat
	// Using template, code size could be bloated, since all these are different functions
	std::cout << square(5.5) << std::endl;

	// Difference between function template and class tempalte
	// data type can be inferred from function input, but need to be explicit specified when deal with class

	BoVector<int> bv;
	bv.push(2);
	bv.push(5);
	bv.push(8);
	bv.push(9);
	bv.print();
	
	std::cout << "Print squared bv: " << std::endl;
	bv = square(bv);
	bv.print();

	std::cin.get();
}

