#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A() { cout << "A's constructor called\n"; }
};

class B : public A {
public:
    B() { cout << "B's constructor called (Single Inheritance)\n"; }
};

class C : public B {
public:
    C() { cout << "C's constructor called (Multilevel Inheritance)\n"; }
};

class D1 : public A {
public:
    D1() { cout << "D1's constructor called\n"; }
};

class D2 : public A {
public:
    D2() { cout << "D2's constructor called\n"; }
};

class E : public D1, public D2 {
public:
    E() { cout << "E's constructor called (Multiple Inheritance)\n"; }
};

class F : virtual public A {
public:
    F() { cout << "F's constructor called (Virtual Inheritance)\n"; }
};

class G : virtual public A {
public:
    G() { cout << "G's constructor called (Virtual Inheritance)\n"; }
};

class H : public F, public G {
public:
    H() { cout << "H's constructor called (Hybrid Inheritance)\n"; }
};

int main() {
    cout << "Creating B object:\n";
    B b;

    cout << "\nCreating C object:\n";
    C c;

    cout << "\nCreating E object:\n";
    E e;

    cout << "\nCreating H object:\n";
    H h;

    return 0;
}
