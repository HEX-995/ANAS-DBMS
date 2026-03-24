#include <iostream>
using namespace std;

class Centimeters; // Forward Declaration

class Meters {
    float m;
public:
    Meters(float x) { m = x; }
    float getMeters() { return m; }

    // Conversion operator to Centimeters
    operator Centimeters();
};

class Centimeters {
    float cm;
public:
    Centimeters(float x) { cm = x; }
    void display() { cout << "Value in Centimeters: " << cm << endl; }
};

// Define conversion operator outside class
Meters::operator Centimeters() {
    return Centimeters(m * 100);
}

int main() {
    Meters m1(7);        // 7 meters
    Centimeters c1 = m1; // Class-to-class conversion using operator
    c1.display();
    return 0;
}
