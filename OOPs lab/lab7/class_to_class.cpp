#include <iostream>
using namespace std;

class Meters {
    float m;
public:
    Meters(float x) { m = x; }
    float getMeters() { return m; }
};

class Centimeters {
    float cm;
public:
    // Constructor to convert Meters to Centimeters
    Centimeters(Meters obj) {
        cm = obj.getMeters() * 100; // 1 meter = 100 cm
    }
    void display() {
        cout << "Value in Centimeters: " << cm << endl;
    }
};

int main() {
    Meters m1(5);       // 5 meters
    Centimeters c1 = m1; // Class-to-class conversion
    c1.display();
    return 0;
}
