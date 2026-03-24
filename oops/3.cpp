#include <iostream>
using namespace std;

class Person {
    string name;
    int age;
public:
    Person() {
        name = "Unknown";
        age = 0;
    }
    Person(string n) {
        name = n;
        age = 0;
    }
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void show() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1;
    Person p2("Ali");
    Person p3("Dilshad", 25);
    const Person p4("Zara", 30);
    p1.show();
    p2.show();
    p3.show();
    p4.show();
    return 0;
}
