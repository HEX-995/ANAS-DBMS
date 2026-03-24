#include<bits/stdc++.h>
using namespace std;

int main() {
    int age;
    cout<<"enter your age"<<endl;
    cin>>age;
    if(age<18){
        cout<<"not eligible for job";
    }
    else if(age<=54){
        cout<<"Eligible for job";
    }
    else if(age<=57){
        cout<<"Eligible for job but retirement soon";
    }
    else{
        cout<<"retirement time";
    }
}
