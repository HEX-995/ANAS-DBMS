#include<iostream>
using namespace std;
int main(){
    int value = 20;
    int another_value = 30;
    int* const ptr = &value;
    cout<<*ptr;
    *ptr = 45; // data change is allowed 
    cout<<endl<<"After change"<<*ptr;
    // ptr = & another_value; // pointer re-assignment is not allowed 
    // cout<<endl<<*ptr;
    return 0;
}