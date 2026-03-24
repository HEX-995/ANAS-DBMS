#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"20/n"<<endl;
    cout<<"enter value of n: ";
    cin>>n;
    try{
        if(n==0){
            throw "zero is not allowed";
        }
        // else if(n<0){
        //     throw n;
        // }
        cout<<20/n;
    }
    catch(const char*msg){
        cout<<"exception: "<<msg;
    }
    // catch(int n){
    //     cout<<"exception: "<<n<<" is a negative integer.";
    // }
    return 0;
}