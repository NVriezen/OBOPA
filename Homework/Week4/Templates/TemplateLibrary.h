#pragma once

namespace TempLib {
	/// Sorting Assignment ///
	template<typename T>
	bool sort(T* ar, size_t size);

	template<typename T>
	bool sort(T* ar, size_t size)
	{
		for (size_t j = 1; j < size; j++) {
			if (ar[j] < ar[j - 1]) {
				T temp = ar[j-1];
				ar[j - 1] = ar[j];
				ar[j] = temp;
				if ((j-1) > 0) {
					j = j - 2;
				}
			}
				
		}

		return true;
	}

	/// Container Class Assignment ///
	template<class T>
	class Arras {
	private:
		size_t length;
		T* arras;
	public:
		Arras() {
			length = 0;
			arras = new T[length];
		}

		bool put(T input) {
			T* newArray = new T[length+1];
			/*
			for (size_t k = size(); k < (size() + 1); k++) {
				newArray[k+1] = arras[k];
			}
			*/
			for (size_t l = 0; l < length; l++) {
				newArray[l] = arras[l];
			}
			newArray[length] = input;
			arras = newArray;
			length++;
			return true;
		}

		//T get(size_t index = 0) {
		T get(){
			return T(arras[0]);
		}

		size_t size() {
			return length;
		}
	};

}
