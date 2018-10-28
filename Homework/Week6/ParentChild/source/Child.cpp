#include "Child.h"

Child::Child(std::string name) {
    this->name = name;
}

Child::Child(const Child& other) {
    this->name = other.name;
}

Child::~Child(){
	std::cout << "cleaned: " << this->name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Child& child) {
    os << "name: " << child.name;
    return os;
}

