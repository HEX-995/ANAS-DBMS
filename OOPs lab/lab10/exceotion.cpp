// wap to demonstrate basic exception handling
// wap to show the use of multiple catch blocks
// wap to use user defined exception classes 

#include <iostream>
using namespace std;

int main() {
    int numerator, denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        if (denominator == 0) {
            // throwing an exception if denominator is zero
            throw "Division by zero error!";
        }
        double result = (double) numerator / denominator;
        cout << "Result: " << result << endl;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}
