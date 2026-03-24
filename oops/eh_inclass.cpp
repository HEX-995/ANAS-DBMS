#include <iostream>
using namespace std;

class DivisionByZero {
public:
    void showMessage() {
        cout << "Exception: Division by zero not allowed!" << endl;
    }
};

int main() {
    int numerator, denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        if (denominator == 0) {
            throw DivisionByZero();   
        }
        cout << "Result = " << (float)numerator / denominator << endl;
    }
    catch (DivisionByZero e) {
        e.showMessage(); 
    }

    cout << "Program continues normally..." << endl;
    return 0;
}
