#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("data.txt");
    ofstream outputFile("updated.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Could not open 'data.txt'." << endl;
        return 1;
    }

    string searchWord = "AI";
    string replaceWord = "Artificial Intelligence";
    string line;

    while (getline(inputFile, line)) {
        size_t pos = 0;

        // Find and replace all occurrences in the current line
        while ((pos = line.find(searchWord, pos)) != string::npos) {
            line.replace(pos, searchWord.length(), replaceWord);
            pos += replaceWord.length();  // Move past the replaced word
        }

        outputFile << line << endl;  // Write modified line to new file
    }

    cout << "All occurrences of '" << searchWord << "' have been replaced with '"
         << replaceWord << "' in 'updated.txt'." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
