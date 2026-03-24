//wap to implement type conversion from basic to class type
//wap to implement type conversion from class to basic type
//wap to implement type conversion from one class to another classtype using constructor and casting operator
#include <iostream>
using namespace std;

class Time {
    int hours, minutes;
public:
    Time(int t) {
        hours = t / 60;
        minutes = t % 60;
    }
    void display() {
        cout << hours << " Hours " << minutes << " Minutes" << endl;
    }
};

int main() {
    int duration = 130;
    Time t1 = duration;
    t1.display();
    return 0;
}
