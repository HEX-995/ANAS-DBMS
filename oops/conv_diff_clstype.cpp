#include <iostream>
using namespace std;

class B;
class A
{
    int x;

public:
    A(int a = 0) { x = a; }
    int getX() { return x; }
    operator B();
};

class B
{
    int y;

public:
    B(int b = 0) { y = b; }
    // B(A a) { y = a.getX(); }
    int getY() { return y; }
};

A::operator B()
{
    return B(getX());
}

int main()
{
    A objA(10);
    B objB1 = objA;
    cout << objB1.getY() << endl;
    return 0;
}
