//Write a C++ program to read the contents of a text file named input.txt and count the number of characters, words, and lines present in it. Display all three counts on the console.

// Write a C++ program that copies the contents of source.txt into another file named destination.txt. If the source file does not exist, display an error message.

// Write a program that reads a text file data.txt and replaces all occurrences of a given word (e.g., “AI”) with another word (e.g., “Artificial Intelligence”). The updated content should be saved in a new file updated.txt.

//Two files — classA.txt and classB.txt — contain names of students (one per line). Write a C++ program to: Merge both files into a new file merged.txt. Sort the names in alphabetical order. Display the sorted list on the console. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");  // Open the file

    if (!file.is_open()) {
        cout << "Error: Could not open file 'input.txt'." << endl;
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    string line;

    while (getline(file, line)) {
        lineCount++;                        // Count lines
        charCount += line.length() + 1;     // +1 for the newline character

        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) {
                inWord = false;
            } else if (!inWord) {
                inWord = true;
                wordCount++;                 // New word starts
            }
        }
    }

    file.close();

    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    return 0;
}