#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual void area() = 0;  // pure virtual function
};

// Derived Class
class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}
    void area() override {
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }
};

// Derived Class
class Rectangle : public Shape {
    int l, b;
public:
    Rectangle(int x, int y) : l(x), b(y) {}
    void area() override {
        cout << "Area of Rectangle = " << l * b << endl;
    }
};

int main() {
    Shape* s;   // pointer of abstract class

    Circle c(5);
    Rectangle r(4, 6);

    s = &c;  
    s->area();  // Circle's implementation

    s = &r;  
    s->area();  // Rectangle's implementation
}
