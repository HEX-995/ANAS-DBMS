// wap to implement type conversion from basic to class type
// wap to implement type conversion from class to basic type
// wap to implement type conversion from one class to another class type using constructor and casting operator 

#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    // Constructor for converting int (basic type) to class type
    Distance(int m) {
        meters = m;
    }

    void display() {
        cout << "Distance: " << meters << " meters" << endl;
    }
};

int main() {
    int basicValue = 50;

    // Basic type (int) converted to class type using constructor
    Distance d = basicValue;  // Implicit conversion

    d.display();

    // Explicit conversion
    Distance d2 = Distance(100);
    d2.display();

    return 0;
}
