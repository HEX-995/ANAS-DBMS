#include <bits/stdc++.h>
using namespace std;

// Base class with virtual function
class A {
public:
    virtual void display() {
        cout << "class A" << endl;
    }
};

class B : public A {
public:
    void display() override {
        cout << "class B" << endl;
    }
};

class C : public A {
public:
    void display() override {
        cout << "class C" << endl;
    }
};

// Class with nested class
class Outer {
public:
    class Inner { // Nested class
    public:
        Inner() {
            cout << "Inner class object created" << endl;
        }
    };
};

// Base class with constructor & virtual destructor
class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual ~Base() { // must be virtual to ensure proper cleanup
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    cout << "\n--- Runtime Polymorphism ---" << endl;
    A* ptr;     // base class pointer
    B objB;
    C objC;

    ptr = &objB;
    ptr->display();   // calls B's display()

    ptr = &objC;
    ptr->display();   // calls C's display()

    cout << "\n--- Nested Class ---" << endl;
    Outer::Inner objInner;  // creating object of nested class

    cout << "\n--- Virtual Destructor ---" << endl;
    Base* bp = new Derived(); // base pointer -> derived object
    delete bp; // invokes both Derived & Base destructors

    return 0;
}
