// wap to implement different types of inheritence with all visibility mode of parent class
// Implement abstract and virtual class inheritence
// using constructor create object of derived class and parent class for different types of inheritence

#include <iostream>
using namespace std;

class Base {
public:
    int pubVar;
protected:
    int protVar;
private:
    int privVar; // never inherited

public:
    Base() {
        pubVar = 1;
        protVar = 2;
        privVar = 3;
    }
    void showBase() {
        cout << "Base: pubVar=" << pubVar 
             << " protVar=" << protVar 
             << " privVar=" << privVar << endl;
    }
};

//  PUBLIC INHERITANCE 
class DerivedPublic : public Base {
public:
    void show() {
        cout << "DerivedPublic: pubVar=" << pubVar << endl;
        cout << "DerivedPublic: protVar=" << protVar << endl;
    }
};

//  PROTECTED INHERITANCE 
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "DerivedProtected: pubVar=" << pubVar << endl;
        cout << "DerivedProtected: protVar=" << protVar << endl;
        
    }
};

//  PRIVATE INHERITANCE 
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "DerivedPrivate: pubVar=" << pubVar << endl;
        cout << "DerivedPrivate: protVar=" << protVar << endl;
      
    }
};

int main() {
    DerivedPublic dp;
    dp.show();
    dp.pubVar = 10;   
    cout << "Access dp.pubVar = " << dp.pubVar << endl;

    DerivedProtected dpr;
    dpr.show();
   
    
    DerivedPrivate dpri;
    dpri.show();

    return 0;
}
