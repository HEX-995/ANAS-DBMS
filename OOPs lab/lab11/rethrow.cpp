#include <iostream>
using namespace std;

void testFunction() {
    try {
        cout << "Inside testFunction()\n";
        throw 20;   // throwing an integer exception
    }
    catch (int e) {
        cout << "Caught exception inside testFunction: " << e << endl;
        cout << "Rethrowing exception...\n";
        throw;  // rethrowing the same exception
    }
}

int main() {
    try {
        testFunction();
    }
    catch (int e) {
        cout << "Caught exception again in main: " << e << endl;
    }

    cout << "Program continues normally..." << endl;
    return 0;
}
