#include <bits/stdc++.h>
using namespace std;

class Person { 
public:
    virtual void display() = 0; 
};

class Student : virtual public Person {
protected:
    int rollNo;
public:
    Student(int r) { rollNo = r; }
    void display() override {
        cout << "Student Roll No: " << rollNo << endl;
    }
};

class Marks : virtual public Person {
protected:
    int marks;
public:
    Marks(int m) { marks = m; }
    void display() override {
        cout << "Marks: " << marks << endl;
    }
};

class Result : public Student, public Marks {
public:
    Result(int r, int m) : Student(r), Marks(m) {}
    void display() override {
        cout << "Result:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Result r(101, 95);
    r.display();
    return 0;
}
