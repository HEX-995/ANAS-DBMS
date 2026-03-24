#include<bits/stdc++.h>
using namespace std;
class subject{
    private:
    int marks;
    public:
    subject(int num){
        marks=num;
    }
    void display(){
        cout<<marks<<endl;
    }
};
int main(){
    subject s1(89);
    s1.display();
}