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

    member(string teacher,string leader){
        (*this).teacher=teacher;
        this->leader=leader;
    }
    //accessing private members
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
    member m1("shiv dutt","krishna");
    m1.name = "Dilshad";
    m1.college = "IIIT Una";
    m1.set_username("dilshad2005");
    m1.set_password(12349678);
    cout << m1.name << "\n"
         << m1.college << "\n";
    
    //m1.show_private();
    cout<<m1.teacher;
    return 0;
}