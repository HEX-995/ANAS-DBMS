#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("data.txt");     
    if (!inputFile) {
        cout << "Error: data.txt not found!" << endl;
        return 1;
    }

    ofstream outputFile("updated.txt");  
    if (!outputFile) {
        cout << "Error: Could not create updated.txt!" << endl;
        return 1;
    }

    string target = "AI";                    
    string replacement = "Artificial Intelligence"; 
    string line;

    while (getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(target, pos)) != string::npos) {
            line.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
        outputFile << line << endl; 
    }

    cout << "All occurrences of \"" << target << "\" replaced successfully!" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
