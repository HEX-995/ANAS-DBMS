#include <iostream>
using namespace std;

class A {
public:
    int a = 1;
};

class B : public A {
public:
    int b = 2;
};

class C {
public:
    int c = 3;
};

class D : public B, protected C {
public:
    void show() {
        cout << "[Hybrid] a=" << a << " b=" << b << " c=" << c << endl;
    }
};

int main() {
    D obj;
    obj.show();
    cout << "Access obj.a = " << obj.a << endl; //  from A
    // cout << obj.c;  not accessible (protected)
    return 0;
}
