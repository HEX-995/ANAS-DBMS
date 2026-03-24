#include <iostream>
using namespace std;

class Outer {
public:
    // Nested class
    class Inner {
        int value;
    public:
        // Constructor
        Inner(int v) {
            value = v;
        }

        void show() {
            cout << "Inner class value = " << value << endl;
        }
    };
};

int main() {
    // Creating objects of nested class using constructor
    Outer::Inner obj1(10);
    Outer::Inner obj2(20);

    obj1.show();
    obj2.show();

    return 0;
}
