/* 03.09.2025
1)WAP to implement diff types of inheritance with differnent visibility mode of parent class.
2)Implement abstract class and virtual base class inheritance.
3)Using constructor create object of derived class and parent class for different type of inheritance.
*/
#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    string name;
    int roll_no;
    A(string name, int roll_no)
    {
        this->name = name;
        this->roll_no = roll_no;
    }
};
class B :virtual public A
{
public:
    string branch;
    B(string name, int roll_no, string branch) : A(name, roll_no)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->branch = branch;
    }
};
class C :virtual public A
{
public:
    long int ph_no;
    C(string name, int roll_no, long int ph_no) : A(name, roll_no)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->ph_no = ph_no;
    }
};

int main()
{
    C c1("Aman", 24141, 9434287433);
    cout << c1.name << endl<< c1.roll_no << endl<< c1.ph_no<<endl;
   
    return 0;
}