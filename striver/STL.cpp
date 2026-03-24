#include <bits/stdc++.h>
using namespace std;
int main()
{
    // PAIRS
    pair<int, int> p1 = {3, 4};
    pair<int, pair<int, int>> p2 = {5, {6, 7}};
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << p1.second << endl;
    cout << p2.second.second << endl;
    cout << arr[1].first << endl;

    // VECTOR
    vector<int> p;
    p.push_back(1);
    p.emplace_back(2);
    p.emplace_back(3);
    p.insert(p.begin()+1,2,20);   
    cout<<"new"<<endl;
    for (int j = 0; j < 5; j++)
    {
        cout << p[j] << endl;
    }

    cout<<"pointer"<<endl;
    for(vector<int>::iterator i=p.begin();i!=p.end();i++){
        cout<<*(i)<<endl;
    }
    return 0;
}