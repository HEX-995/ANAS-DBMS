#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");  
    if (!file) {
        cout << "Error: Could not open the file!" << endl;
        return 1;
    }

    int charCount = 0, wordCount = 0, lineCount = 0;
    string line;

    
    while (getline(file, line)) {
        lineCount++;                  
        charCount += line.length();   

       
        bool inWord = false;
        for (char ch : line) {
            if (isspace(ch)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) wordCount++; 
    }

    file.close();

    
    charCount += lineCount - 1;

    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    return 0;
}
