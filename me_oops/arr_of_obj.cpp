#include <bits/stdc++.h>
using namespace std;
class employee
{
public:
    string name, role;
    int salary;
    void get_data()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Role: ";
        cin >> role;
        cout << "Salary: ";
        cin >> salary;
    }
    void display_data()
    {
        cout << "Name: " << name << endl
             << "Role: " << role << endl
             << "Salary: " << salary << endl;
    }
};
int main()
{
    employee a[3];
    for(int i=0;i<3;i++){
        a[i].get_data();
    }
    for(int i=0;i<3;i++){
        a[i].display_data();
    }
    return 0;
}