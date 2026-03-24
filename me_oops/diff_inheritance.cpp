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
class B : public A
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
class M
{
public:
    string name;
    M(string name)
    {
        this->name = name;
    }
};
class N
{
public:
    int roll_no;
    N(int roll_no)
    {
        this->roll_no=roll_no;
    }
};
class O:public M,public N{
    public:
    string branch;
    O(string name,int roll_no,string branch):M(name),N(roll_no){
        this->name=name;
        this->roll_no=roll_no;
        this->branch=branch;
    }
};
int main()
{
    A a1("Dilshad", 24140);
    cout << a1.name << endl<< a1.roll_no << endl;
    B b1("Aman", 24141, "CSE");
    cout << b1.name << endl<< b1.roll_no << endl<< b1.branch<<endl;
    O o1{"shourya",24163,"CSE"};
    cout<<o1.name<<endl<<o1.roll_no<<endl<<o1.branch<<endl;
    return 0;
}