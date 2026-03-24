#include <iostream>
using namespace std;

class Base1 {
public:
    int pub1 = 10;
protected:
    int prot1 = 20;
};

class Base2 {
public:
    int pub2 = 30;
protected:
    int prot2 = 40;
};

// Public multiple inheritance
class Derived : public Base1, public Base2 {
public:
    void show() {
        cout << "[Multiple Inheritance] pub1=" << pub1 << " prot1=" << prot1
             << " pub2=" << pub2 << " prot2=" << prot2 << endl;
    }
};

int main() {
    Derived obj;
    obj.show();
    cout << "Access obj.pub1=" << obj.pub1 << " obj.pub2=" << obj.pub2 << endl; // ✅
    return 0;
}
