#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fileA("classA.txt");
    ifstream fileB("classB.txt");
    ofstream mergedFile("merged.txt");

    if (!fileA || !fileB) {
        cout << "Error: One or both input files could not be opened!" << endl;
        return 1;
    }

    vector<string> names;
    string name;

    while (getline(fileA, name)) {
        if (!name.empty())
            names.push_back(name);
    }

    while (getline(fileB, name)) {
        if (!name.empty())
            names.push_back(name);
    }

    fileA.close();
    fileB.close();

    sort(names.begin(), names.end());

    for (const string &n : names) {
        mergedFile << n << endl;
    }

    mergedFile.close();

    cout << "Sorted list of students (merged):" << endl;
    for (string n : names) {
        cout << n << endl;
    }

    return 0;
}
