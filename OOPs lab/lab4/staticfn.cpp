#include<iostream>
using namespace std;

class check{
    private:
    static int age;
    static int salary;

    public:
    static void print(){
        cout<<"Age is: "<<age<<endl;
        cout<<"salary is: "<<salary<<endl;
    }
};

int check::age;
int check::salary;

int main(){
    check c1;

    c1.print();

    cout<<endl;

    check::print();

    return 0;
}