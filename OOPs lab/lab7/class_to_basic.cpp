#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    Distance(int m) {
        meters = m;
    }

    // Conversion function: Class to int
    operator int() {
        return meters;
    }
};

int main() {
    Distance d(20);

    // Class object converted to int
    int basicValue = d;  // Calls operator int()

    cout << "Distance in meters: " << basicValue << endl;

    return 0;
}
