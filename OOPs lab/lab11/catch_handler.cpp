#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Inside try block\n";

        // Throwing different types of exceptions
        throw 10;         // int exception
        // throw "error"; // string exception
        // throw 3.14;    // double exception
    }
    catch (int e) {
        cout << "Caught an integer exception: " << e << endl;
    }
    catch (const char* msg) {
        cout << "Caught a string exception: " << msg << endl;
    }
    catch (...) {
        cout << "Caught an unknown exception!" << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}
