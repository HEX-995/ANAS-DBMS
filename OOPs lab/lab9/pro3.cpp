#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }

    // Virtual destructor
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }

    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    // Base class pointer, dynamic allocation of Derived
    Base* ptr = new Derived();

    // Deleting using base pointer
    delete ptr;  

    return 0;
}
