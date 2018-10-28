#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
    this->name = name;
    std::string childName = "ChildOf" + name;
	this->child = std::make_unique<Child>(childName);//new Child(childName);
}

Parent::Parent(const Parent& other) {
    std::cout << "Parent cctor" << std::endl;
    this->name = other.name;
    this->child = std::make_unique<Child>(*other.child);//new Child(*other.child);
}

Parent::~Parent() {
    //delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
    std::cout << "Parent assignment" << std::endl;

    if (this == &other) {
        return *this;
    }

    this->name = other.name;
    //delete this->child;
    this->child = std::make_unique<Child>(*other.child);//new Child(*other.child);
	//this->child = std::move(*other.child);

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
    os << "name: " << parent.name << " child: " << *parent.child;
    return os;
}
