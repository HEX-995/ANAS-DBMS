#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int roll;
    char grade;
};

// Function to safely read integer input
int safeIntInput(const string &prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function to safely read char input
char safeCharInput(const string &prompt) {
    char c;
    while (true) {
        cout << prompt;
        if (cin >> c) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return c;
        } else {
            cout << "Invalid input. Please enter a character.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void addRecords() {
    ofstream outFile("student.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int n = safeIntInput("How many students to add? ");
    Student s;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, s.name);
        s.roll = safeIntInput("Roll No: ");
        s.grade = safeCharInput("Grade: ");
        outFile << s.name << " " << s.roll << " " << s.grade << endl;
    }
    outFile.close();
    cout << "\nRecords added successfully.\n";
}

void displayRecords() {
    ifstream inFile("student.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    int count = 0;
    cout << "\nAll Student Records:\n";
    while (inFile >> s.name >> s.roll >> s.grade) {
        cout << "Name: " << s.name << ", Roll: " << s.roll << ", Grade: " << s.grade << endl;
        count++;
    }
    cout << "\nTotal Records: " << count << endl;
    inFile.close();
}

void searchByRoll() {
    ifstream inFile("student.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int searchRoll = safeIntInput("\nEnter roll number to search: ");
    Student s;
    bool found = false;

    while (inFile >> s.name >> s.roll >> s.grade) {
        if (s.roll == searchRoll) {
            cout << "\nRecord Found:\n";
            cout << "Name: " << s.name << ", Roll: " << s.roll << ", Grade: " << s.grade << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Record with roll number " << searchRoll << " not found.\n";
    inFile.close();
}

int main() {
    int choice;
    do {
        choice = safeIntInput("\nMenu:\n1. Add Records\n2. Display Records\n3. Search by Roll No\n4. Exit\nEnter your choice: ");
        switch (choice) {
            case 1: addRecords(); break;
            case 2: displayRecords(); break;
            case 3: searchByRoll(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
