#include <iostream>
using namespace std;

class Grandparent {
public:
    int gpub = 1;
protected:
    int gprot = 2;
};

class Parent : public Grandparent {
public:
    void showParent() {
        cout << "[Parent] gpub=" << gpub << " gprot=" << gprot << endl;
    }
};

class Child : public Parent {
public:
    void showChild() {
        cout << "[Child] gpub=" << gpub << " gprot=" << gprot << endl;
    }
};

int main() {
    Child obj;
    obj.showParent();
    obj.showChild();
    cout << "Access obj.gpub=" << obj.gpub << endl; //  only if public inheritance
    return 0;
}
