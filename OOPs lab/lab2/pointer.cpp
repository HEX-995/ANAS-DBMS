// pointer to constant 
// constant pointer to pointer 

// passing the function by 1. value  2. by reference 

// accessing array elements of 1d 2d 3d using indexing and pointers 

#include<iostream>
using namespace std;
int main(){
    // pointer to constant data
    int value = 10;
    int another_value = 20;
    const int* ptr = &value;
    cout<<*ptr;
    /*
    *ptr = 15;
    cout<<*ptr;
    // ...... this value can not be changed 
    */
    ptr = &another_value;
    cout<<endl<<*ptr;
    return 0;
}