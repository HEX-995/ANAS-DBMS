#include<iostream>
using namespace std;
int main(){
    int value = 20;
    int another_value = 30;
    const int* const ptr = &value;
    cout<<*ptr;
    // *ptr = 24;
    // ptr = &another_value; ........... both will give error
    return 0;
}