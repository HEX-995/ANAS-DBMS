#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream fileA("classA.txt");
    ifstream fileB("classB.txt");
    ofstream mergedFile("merged.txt");

    if (!fileA.is_open() || !fileB.is_open()) {
        cout << "Error: Could not open one or both source files." << endl;
        return 1;
    }

    vector<string> names;
    string name;

    // Read names from classA.txt
    while (getline(fileA, name)) {
        if (!name.empty())
            names.push_back(name);
    }

    // Read names from classB.txt
    while (getline(fileB, name)) {
        if (!name.empty())
            names.push_back(name);
    }

    // Sort names alphabetically
    sort(names.begin(), names.end());

    // Write sorted names to merged.txt and display on console
    cout << "Sorted list of students:\n";
    for (string n : names) {
        mergedFile << n << endl;
        cout << n << endl;
    }

    cout << "\nMerged and sorted names saved to 'merged.txt'." << endl;

    fileA.close();
    fileB.close();
    mergedFile.close();

    return 0;
}
