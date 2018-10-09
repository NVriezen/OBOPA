#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cctype>

//using namespace std;

void print(std::vector<std::string> words);

int main() {
    std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    // 2) alle elementen UPPERCASE te maken.
    // 3) alle dubbele te verwijderen

	//1)
	std::vector<std::string> coloursCopy1(colours);
	std::vector<std::string> beforePurple(colours.size());
	std::vector<std::string> afterPurple(colours.size());
	std::vector<std::string>::iterator i;
	sort(coloursCopy1.begin(), coloursCopy1.end());
	i = find(coloursCopy1.begin(), coloursCopy1.end(), "purple");

	copy(coloursCopy1.begin(), i, beforePurple.begin());
	copy((i+1), coloursCopy1.end(), afterPurple.begin());

	i = find(beforePurple.begin(), beforePurple.end(), "");
	beforePurple.resize(std::distance(beforePurple.begin(), i));

	i = find(afterPurple.begin(), afterPurple.end(), "");
	afterPurple.resize(std::distance(afterPurple.begin(), i));

	print(beforePurple);
	print(afterPurple);

	//2)
	std::vector<std::string> coloursCopy2(colours);
	for (auto col : coloursCopy2) {
		std::transform(col.begin(), col.end(), col.begin(), ::toupper);
	}

	print(coloursCopy2);

	//3)
	std::vector<std::string> noDuplicates(colours);// = colours;
	//noDuplicates.swap(colours);
	std::vector<std::string>::iterator it;
	it = unique_copy(colours.begin(), colours.end(), noDuplicates.begin());
	noDuplicates.resize(distance(noDuplicates.begin(), it));
	sort(noDuplicates.begin(), noDuplicates.end());
	it = unique_copy(noDuplicates.begin(), it, noDuplicates.begin());
	noDuplicates.resize(distance(noDuplicates.begin(), it));

	print(noDuplicates);

	std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) alle negatieve elementen te verwijderen
    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    // 3) de som, het gemiddelde, en het product van alle getallen te berekenen

	//1)
	std::vector<double> numbersCopy(numbers);
	std::vector<double>::iterator ite;
	ite = std::remove_if(numbersCopy.begin(), numbersCopy.end(), [](int i) { return i < 0 ? true : false; });
	numbersCopy.resize(std::distance(numbersCopy.begin(), ite));

	std::cout << "--- BEGIN ---" << std::endl;
	for (auto word : numbersCopy) {
		std::cout << word << std::endl;
	}
	std::cout << "--- END ---" << std::endl;

	//2)
	std::cout << "--- BEGIN ---" << std::endl;
	for (auto word : numbers) {
		//[](int word) { return (std::modulus<int>(word, 2) == 0 ? "true" : "false"); }
		if ((int)word % 2 == 0) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
	}
	std::cout << "--- END ---" << std::endl;

	//3)
	std::vector<double> result(1);
	std::transform(numbers.begin(), numbers.end(), result.begin(), std::plus<double>());

    return 0;
}

//template<typename T>
void print(std::vector<std::string> words) {
	std::cout << "--- BEGIN ---" << std::endl;
	for (auto word : words) {
		std::cout << word << std::endl;
	}
	std::cout << "--- END ---" << std::endl;
}