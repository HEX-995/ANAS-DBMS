#include <iostream>
using namespace std;

class MyClass {
private:
    static int count; // static data member

public:
    // Static function to access static data
    static void setCount(int value) {
        count = value;
    }

    static void showCount() {
        cout << "Count = " << count << endl;
    }
};

// Static data member ko class ke bahar define karna padta hai
int MyClass::count = 0;

int main() {
    // Static functions ko object banaye bina call kar sakte ho
    MyClass::setCount(5);
    MyClass::showCount();

    // Object se bhi call kar sakte ho
    MyClass obj;
    obj.setCount(10);
    obj.showCount();

    return 0;
}
