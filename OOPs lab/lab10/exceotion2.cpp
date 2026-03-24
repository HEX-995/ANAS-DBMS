#include <iostream>
using namespace std;

int main() {
    try {
        int choice;
        cout << "Enter 1 for integer exception, 2 for char exception, 3 for float exception: ";
        cin >> choice;

        if (choice == 1) {
            throw 100;  // int exception
        } else if (choice == 2) {
            throw 'A';  // char exception
        } else if (choice == 3) {
            throw 3.14f; // float exception
        } else {
            throw string("Unknown choice"); // string exception
        }
    }
    catch (int e) {
        cout << "Caught an integer exception: " << e << endl;
    }
    catch (char e) {
        cout << "Caught a character exception: " << e << endl;
    }
    catch (float e) {
        cout << "Caught a float exception: " << e << endl;
    }
    catch (string e) {
        cout << "Caught a string exception: " << e << endl;
    }
    catch (...) {
        cout << "Caught some other unknown exception." << endl;
    }

    cout << "Program continues after handling exception." << endl;
    return 0;
}
