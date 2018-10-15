#pragma once

template <typename T>
class Concurrent_Vector {
private:
	std::vector<T> vect;
	std::mutex mutex;
public:
	bool push_back(T input) {
		//std::lock_guard<std::mutex> guard(mutex);
		mutex.lock();
		vect.push_back(input);
		mutex.unlock();
		return true;
	}
	size_t sizeOf() {
		vect;
	}
	T& at(size_t index) {
		std::lock_guard<std::mutex> guard(mutex);
		if (index >= 0 && index < vect.size())
			return vect[index];
	}
	/*
	T& operator[](int index)
	{
		if (index >= 0 && index < vect.size())
		return vect[index];
	}
	*/



};
