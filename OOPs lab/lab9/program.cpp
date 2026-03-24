// create a base class with virtual function defined two derived classes in which override the virtual function use a base class pointer to demonstrate runtime polymorphism

// design a class that contain a nested class use constructor to create objects of nested class in main

// Create a base class with a constructor and virtual destructor. Derive a class from base class with its own constructor and destructor. Dynamically allocate a derived class object using base class pointer adn delete the object and pointer.Show what happens if constructor is not declared as virtual.

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void sound()  {
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void sound()  {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Base class pointer
    Animal* ptr;

    Dog d;
    Cat c;

    // Pointing to Dog object
    ptr = &d;
    ptr->sound();  // Runtime polymorphism -> Dog's sound() is called

    // Pointing to Cat object
    ptr = &c;
    ptr->sound();  // Runtime polymorphism -> Cat's sound() is called

    return 0;
}
