#include <bits/stdc++.h>
using namespace std;
class member
{
public:
    string name;
    string college;
    string teacher;
    string leader;
    string username;
    int password;
    int *ptr;

    member(string name, int password)
    {
        (*this).name = name;
        ptr = new int;
        *this->ptr = password;
    }
    void info()
    {
        cout << name << "\n";
        cout << *ptr << "\n";
    }
};
int main()
{
    member m1("dilshad", 1234);
    // m1.name = "Dilshad";
    // m1.college = "IIIT Una";
    member m2(m1);
    m2.password = 5678;
    m2.info();
    m1.info();
    return 0;
}