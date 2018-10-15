#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include "Concurrent_Vector.h"

int main() {
	Concurrent_Vector<int>* vecto = new Concurrent_Vector<int>();

	for (size_t i = 0; i < 2000000; i++) {
		std::thread first(&Concurrent_Vector<int>::push_back, vecto, 16);
		//std::thread first(std::cout << "New thread is: " << std::this_thread::get_id() << std::endl);
		std::thread second(&Concurrent_Vector<int>::push_back, vecto, 512);
		first.detach();
		second.detach();

		//vecto[0] = 10;
		std::cout << "" << vecto->at(i) << std::endl;
		//if (vecto->at(i) != 16 || vecto->at(i) != 512) {
		//if (i >= 5){
		//	break;
		//}

		//std::cout << "Main thread is: " << std::this_thread::get_id() << std::endl;
		//std::cout << "Main thread is: " << std:: << std::endl;
	}

	return 0;
}