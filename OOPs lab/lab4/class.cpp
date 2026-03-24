// access private variables using friend function
// use static function to access static data
// passing object to fn
// returning object from function 


#include<iostream>
using namespace std;

class test{
    private:
    int private_var;

    public:
    test(){
        private_var = 10;
    }

    friend void function (test obj);
};

void function(test obj){
    cout<<"private variable is: "<<obj.private_var<<endl;
}

int main(){
    test object1;
    function(object1);

    return 0;
}