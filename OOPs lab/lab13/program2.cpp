#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream source("source.txt", ios::in);      // Open source file for reading
    ofstream destination("destination.txt", ios::out);  // Open destination file for writing

    if (!source.is_open()) {
        cout << "Error: Source file 'source.txt' not found." << endl;
        return 1;
    }

    char ch;
    while (source.get(ch)) {  // Read each character from source
        destination.put(ch);  // Write it to destination
    }

    cout << "File copied successfully to 'destination.txt'." << endl;

    source.close();
    destination.close();

    return 0;
}
