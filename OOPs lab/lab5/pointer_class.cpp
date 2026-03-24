#include<iostream>
using namespace std;


class test{
    private:
        int i1;
        int i2;

    public:

        void input(int x, int y){
            i1 = x;
            i2 = y;
        }

        void display(){
            cout<<i1<<endl<<i2;
        }


};


int main(){
    test t1;
    test *ptr;

    ptr = &t1;

    ptr->input(5,10);
    ptr->display();
    
    return 0;
}