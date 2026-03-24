#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> marks;
    int n, markToRemove;

    // Insert marks dynamically
    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        marks.push_back(m);
    }

    // Display using index-based access
    cout << "\nMarks (Index-based access): ";
    for (int i = 0; i < marks.size(); i++) {
        cout << marks[i] << " ";
    }

    // Display using iterator-based access
    cout << "\nMarks (Iterator-based access): ";
    for (auto it = marks.begin(); it != marks.end(); it++) {
        cout << *it << " ";
    }

    // Remove a specific mark
    cout << "\n\nEnter a mark to remove: ";
    cin >> markToRemove;

    auto it = find(marks.begin(), marks.end(), markToRemove);
    if (it != marks.end()) {
        marks.erase(it);
        cout << "Mark removed successfully!";
    } else {
        cout << "Mark not found!";
    }

    // Sorting vector
    sort(marks.begin(), marks.end());

    // Display sorted marks
    cout << "\nSorted Marks: ";
    for (int m : marks) {
        cout << m << " ";
    }

    // Display highest and lowest marks
    if (!marks.empty()) {
        cout << "\nHighest Mark: " << marks.back();
        cout << "\nLowest Mark: " << marks.front();
    } else {
        cout << "\nNo marks available after deletion.";
    }

    return 0;
}
