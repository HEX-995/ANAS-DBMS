#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    Student s1;
    Student *ptr;
    ptr = &s1;
    ptr->name = "Dilshad";
    ptr->age = 20;
    ptr->display();
    return 0;
}
