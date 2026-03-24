#include <iostream>
using namespace std;

class Base {
public:
    int pub = 100;
protected:
    int prot = 200;
};

class Child1 : public Base {
public:
    void show() { cout << "[Child1] pub=" << pub << " prot=" << prot << endl; }
};

class Child2 : protected Base {
public:
    void show() { cout << "[Child2] pub=" << pub << " prot=" << prot << endl; }
};

int main() {
    Child1 c1;
    c1.show();
    cout << "Access c1.pub = " << c1.pub << endl; // ✅ public

    Child2 c2;
    c2.show();
    // cout << c2.pub; ❌ not accessible (became protected)
    return 0;
}
