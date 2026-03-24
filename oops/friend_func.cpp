// access private variables using friend function
// use static function to access static data
// passing obj to function
// returning object from function
#include <iostream>
using namespace std;

class MyClass {
private:
    int secretNumber; // private variable

public:

    MyClass(int num) {
        secretNumber = num;
    }

    // Friend function declaration
    friend void revealSecret(MyClass obj);//define outside class
};

// Friend function definition
void revealSecret(MyClass obj) {
    // Friend function private variable ko directly access kar sakti hai
    cout << "The secret number is: " << obj.secretNumber << endl;
}

int main() {
    MyClass obj1(42); // Object banaya
    revealSecret(obj1); // Friend function call kiya

    return 0;
}
