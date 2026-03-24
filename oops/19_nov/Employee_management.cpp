#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;

    Employee(int id, string name, double salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
};

// Comparator for sorting by salary
bool compareSalary(const Employee &e1, const Employee &e2) {
    return e1.salary < e2.salary;
}

int main() {
    vector<Employee> employees;
    int n;

    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore();

    // Add employee details
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        double salary;

        cout << "\nEnter Employee " << i + 1 << " ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, salary);
    }

    // Insert employee at specific position
    int pos, newId;
    string newName;
    double newSalary;

    cout << "\nEnter position to insert new employee: ";
    cin >> pos;
    cin.ignore();
    cout << "Enter new employee ID: ";
    cin >> newId;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, newName);
    cout << "Enter Salary: ";
    cin >> newSalary;

    if (pos >= 0 && pos <= employees.size()) {
        employees.insert(employees.begin() + pos, Employee(newId, newName, newSalary));
        cout << "Employee added at position " << pos << endl;
    } else {
        cout << "Invalid position!" << endl;
    }

    // Update salary of an employee by ID
    int searchId;
    cout << "\nEnter employee ID to update salary: ";
    cin >> searchId;

    bool found = false;
    for (auto &emp : employees) {
        if (emp.id == searchId) {
            cout << "Enter new salary: ";
            cin >> emp.salary;
            found = true;
            cout << "Salary updated successfully!\n";
            break;
        }
    }
    if (!found) cout << "Employee not found!\n";

    // Sort by salary
    sort(employees.begin(), employees.end(), compareSalary);

    // Display using iterators
    cout << "\n--- Employee List (Sorted by Salary) ---\n";
    for (auto it = employees.begin(); it != employees.end(); it++) {
        cout << "ID: " << it->id
             << ", Name: " << it->name
             << ", Salary: " << it->salary << endl;
    }

    return 0;
}
