
#include <iostream>

#include "TemplateLibrary.h"

template<typename U>
void print(U arr, size_t size);

template<typename U>
void printArras(U arr);

int main() {

	/// Sorting Assignment ///
	float* pa;
	float floatArray[4] = { 21, 44.4, 56.23, 13.3 };

	pa = floatArray;

	print(floatArray, 4); //Print array

	TempLib::sort(pa, 4);

	print(floatArray, 4); //Print array

	/// Container Class Assignment ///
	TempLib::Arras<int> integers;

	printArras(integers); //Print arras

	integers.put(6);

	printArras(integers); //Print arras

	integers.put(3);

	printArras(integers); //Print arras

	return 0;
}

//Print The array
template<typename U>
void print(U arr, size_t size) {
	std::cout << "------ BEGIN ------" << std::endl;
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " address is: " << &arr[i] << std::endl;
	}
	std::cout << "------- END -------\n" << std::endl;
}

//Print the custom container class
template<typename U>
void printArras(U arr) {
	std::cout << "------ BEGIN ------" << std::endl;
	for (size_t i = 0; i < arr.size(); i++) {
		//std::cout << arr.get(i) << std::endl;
		std::cout << arr.get() << std::endl;
	}
	std::cout << "------- END -------\n" << std::endl;
}