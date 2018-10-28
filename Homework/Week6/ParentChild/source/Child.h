#pragma once

#include <string>
#include <iostream>

//using namespace std;

class Child {
    public:
        Child(std::string name);
        Child(const Child& other);
		~Child();

    private:
        std::string name;

    public:
        friend std::ostream& operator<<(std::ostream& os, const Child& child);
};

