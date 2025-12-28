 5#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void sound() {  // Virtual function
        cout << "Animals make sounds" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void sound() override {  // Overriding the base class function
        cout << "Dogs bark" << endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    void sound() override {  // Overriding the base class function
        cout << "Cats meow" << endl;
    }
};

int main() {
    Animal* animal1;  // Pointer of type Animal
    Dog dog;
    Cat cat;

    animal1 = &dog;  // Pointer points to a Dog object
    animal1->sound();  // Calls the Dog's overridden function

    animal1 = &cat;  // Pointer points to a Cat object
    animal1->sound();  // Calls the Cat's overridden function

    return 0;
}
