#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int roll_no;

public:
    Student(int r = 0)
    {
        roll_no = r;
    }

    void display()
    {
        cout << "Roll Number: " << roll_no << endl;
    }
};

Student createStudent(int r)
{
    Student s(r);
    return s;
}

int main()
{
    Student s1;
    s1 = createStudent(101);
    s1.display();
    return 0;
}
