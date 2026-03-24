#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, wt, tat, ct;
};

int main() {
    int n, t = 0, c = 0;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout<<"process "<<i<<": "<<endl;
        p[i].id = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].wt = p[i].tat = p[i].ct = 0;
    }

    vector<bool> done(n, false);

    while (c < n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= t && (idx == -1 || p[i].bt > p[idx].bt)) {
                idx = i;
            }
        }
        if (idx != -1) {
            t += p[idx].bt;
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            done[idx] = true;
            c++;
        } else {
            t++;
        }
    }

    double twt = 0, ttat = 0;
    cout << "\nResults:\n";
    for (auto &x : p) {
        twt += x.wt;
        ttat += x.tat;
        cout << "P" << x.id 
             << " | CT: " << x.ct 
             << " | WT: " << x.wt 
             << " | TAT: " << x.tat << endl;
    }
    cout << "Average WT: " << twt / n 
         << " | Average TAT: " << ttat / n << endl;
}
