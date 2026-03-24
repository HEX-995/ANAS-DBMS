#include <iostream>
using namespace std;

class Time
{
    int hours, minutes;

public:
    Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    operator int()
    {
        return hours * 60 + minutes;
    }
};

int main()
{
    Time t1(2, 30);
    int duration = t1;
    cout << duration;
    return 0;
}
