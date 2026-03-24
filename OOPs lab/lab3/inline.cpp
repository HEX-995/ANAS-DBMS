#include<iostream>
using namespace std;


inline int square(int x){
    return x * x;
}

int main(){
    cout<<"Area of square is : ";
    cout<<square(5)<<endl;

    return 0;
}