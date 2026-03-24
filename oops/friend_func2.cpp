#include <bits/stdc++.h>
using namespace std;
class lab1
{
private:
    int roll_no;

public:
    lab1(int num)
    {
        roll_no = num;
    }
    friend void f1(lab1 detail);
    friend int f2(lab1 detail);
};
void f1(lab1 detail)
{
    cout << detail.roll_no<<endl;
}
int f2(lab1 detail){
    return detail.roll_no;
}
int main()
{
    int num=10;
    lab1 detail(num);
    f1(detail);
    int x=f2(detail);
    cout<<x;
    return 0;
}