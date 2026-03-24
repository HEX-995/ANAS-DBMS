//function overloading
// inline function 

#include<iostream>
using namespace std;

int area(int length, int breadth){
    return length * breadth;
}

int area(int radius){
    return (3.14 * radius * radius);
}

float area(int radius){
    return (3.14 * radius * radius);
}

double area(double radius1){
    return (3.14 * radius1 * radius1);
}

int main(){

    int rectangle_area = area(2,3);
    int circle_area = area(5);
    int circle_area2 = area(5);
    double circle_area1 = area(5.1);

    cout<<"area of rectangle is "<<rectangle_area<<endl;
    cout<<"circle area is "<<circle_area<<endl;
    cout<<"circle area is "<<circle_area2<<endl;
    cout<<"circle area in float is "<<circle_area1<<endl;

    return 0;
}