#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;

    void getData() {
        cout << "Enter Name: "; cin >> name;
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Salary: "; cin >> salary;
    }

    void showData() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }
};

int main() {
    fstream file("employee.txt", ios::in | ios::out | ios::app);
    if (!file) { cout << "Error opening file!\n"; return 1; }

    int n;
    cout << "How many employees to add? ";
    cin >> n;

    // Adding employee records
    for(int i = 0; i < n; i++) {
        Employee e;
        e.getData();
        file << e.name << " " << e.id << " " << e.salary << endl;
    }

    file.close();

    // Reading and displaying employee by ID
    ifstream inFile("employee.txt");
    int searchId, count = 0;
    cout << "\nEnter ID to search: ";
    cin >> searchId;
    Employee e;
    bool found = false;

    cout << "\nAll Employees:\n";
    while (inFile >> e.name >> e.id >> e.salary) {
        e.showData();
        count++;
        if (e.id == searchId) {
            cout << "\nRecord Found:\n";
            e.showData();
            found = true;
        }
    }

    cout << "\nTotal Records: " << count << endl;
    if (!found) cout << "Record with ID " << searchId << " not found.\n";

    inFile.close();
    return 0;
}
