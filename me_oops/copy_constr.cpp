#include <bits/stdc++.h>
using namespace std;
class member
{
    string username;
    int password;

public:
    string name;
    string college;
    string teacher;
    string leader;

    member(string teacher, string leader)
    {
        (*this).teacher = teacher;
        this->leader = leader;
    }
    member(const member &copy)
    {
        this->college = copy.college;
    }
    // accessing private members
    void set_username(string un)
    {
        this->username = un;
    }
    void set_password(int pass)
    {
        this->password = pass;
    }
    void show_private()
    {
        cout << username << endl
             << password;
    }
};
int main()
{
    member m1("shiv dutt", "krishna");
    m1.name = "Dilshad";
    m1.college = "IIIT Una";
    m1.set_username("dilshad2005");
    m1.set_password(12349678);
    // cout << m1.name << "\n"
    //      << m1.college << "\n";

    // m1.show_private();
    member m2(m1);
    m1.college = "iitmandi";
    cout << m2.name;
    cout << m2.college;
    return 0;
}