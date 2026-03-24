#include<iostream>
using namespace std;
void pass_by_value(int test){
    test = 20;
}

void pass_by_reference(int &test){
    test = 30;
}

int main(){

    int test = 10;
    cout<<test<<endl;

    pass_by_value(test);
    cout<<"After pass by value:--  "<<test<<endl;

    pass_by_reference(test);
    cout<<"After pass by reference:--   "<<test<<endl;
    

    return 0;
}