#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, armst, a;
    cout << "enter the number:\n";
    cin >> num;
    while (num != 0)
    {
        a = num % 10;
        a = a * 10;
        num = num / 10;
    }
    if (a == num)
    {
        cout << "yes\n";
    }
    return 0;
}
