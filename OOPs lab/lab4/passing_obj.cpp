#include<iostream>
using namespace std;

class complex_number{
    public:
    int real_part;
    int imag_part;

    complex_number add(complex_number c1, complex_number c2){
        complex_number c3;

        c3.real_part = c1.real_part + c2.real_part;
        c3.imag_part = c1.imag_part + c2.imag_part;

        return c3;
    }

    void print(){
        cout<<"real part is: "<<this->real_part<<endl;
        cout<<"Imagniary part is: "<<this->imag_part<<endl;
    }

};


int main(){

    complex_number C1;
    C1.real_part = 5;
    C1.imag_part = 2;

    complex_number C2;
    C2.real_part = 2;
    C2.imag_part = 5;

    complex_number c3;
    c3 =  c3.add(C1, C2);

    C1.print();
    C2.print();
    c3.print();


    return 0;
}