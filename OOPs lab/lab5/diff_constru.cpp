#include<iostream>
using namespace std;

class test{
    private:
        int i1;
        int i2;
    public:
        test(){
            i1 = 0;
            i2 = 0;
        }
        test(int x){
            i1 = x;
            i2 = 0;
        }
        test(int x, int y){
            i1 = x;
            i2 = y;
        }

        void display() const{
            cout<<i1<<endl<<i2<<endl;
        }

        void display(){
            cout<<endl<<"without const"<<endl;
            cout<<i1<<endl<<i2<<endl;
        }
};



int main(){

    test t1;
    t1.display();

    test t2(5, 7);
    t2.display();

    const test t3(8, 2);
    t3.display();

    return 0;
}