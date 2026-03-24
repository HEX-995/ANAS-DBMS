#include <iostream>
using namespace std;

// User-defined exception class
class MyException {
public:
    string message;
    MyException(string msg) {
        message = msg;
    }
};

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try {
        if (age < 18) {
            throw MyException("You must be at least 18 years old!");
        }
        cout << "Access granted. Age is " << age << endl;
    }
    catch (MyException &e) {
        cout << "Caught exception: " << e.message << endl;
    }


    cout << "Program continues after exception handling." << endl;
    return 0;
}
