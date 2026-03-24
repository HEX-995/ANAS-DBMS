#include <iostream>
#include <vector>
#include <list>
#include <algorithm>   // for sort
using namespace std;

int main() {
    vector<int> v;
    int x;

    // Step 1: Create vector<int> and input 10 values
    cout << "Enter 10 integers for the vector:\n";
    for (int i = 0; i < 10; i++) {
        cin >> x;
        v.push_back(x);
    }

    // Step 2: Convert vector to list using iterators
    list<int> list1(v.begin(), v.end());

    // Step 3: Create another list<int> and input values
    list<int> list2;
    int n;
    cout << "\nEnter number of elements for second list: ";
    cin >> n;

    cout << "Enter " << n << " integers for the second list:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list2.push_back(x);
    }

    // Step 4: Sort both lists before merging
    list1.sort();
    list2.sort();

    // Step 5: Merge second list into first
    list1.merge(list2);

    // Step 6: Remove duplicates using unique() (works on consecutive equal elements)
    list1.unique();

    // Step 7: Display the merged sorted list
    cout << "\nMerged, sorted list (duplicates removed):\n";
    for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
