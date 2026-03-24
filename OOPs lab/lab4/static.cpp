#include<iostream>
using namespace std;

class student{
    public:
    static int total;

    student(){
        total = total + 1;
    }
};

int student::total; // definition 

int main(){
   
    student s1;
    cout << "Number of students:" << s1.total << endl;

    return 0;
}