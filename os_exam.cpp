
#include <bits/stdc++.h>
using namespace std;

struct Package {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    bool completed;
};
void sort(vector<Package> &p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void scheduling(vector<Package> &p, int n) {
    int completedCount = 0;
    int currentTime = 0;

    while (completedCount < n) {
        int idx = -1;
        int minBT = INT_MAX;
        sort(p, n);
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= currentTime) {
                if (p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                } else if (p[i].bt == minBT && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            currentTime += p[idx].bt;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;
            completedCount++;
        } else {
            currentTime++;
        }
    }
}

int main() {

    vector<Package> package = {
        {2,1,4,0,0,0,false},
        {3,2,9,0,0,0,false},
        {1,0,8,0,0,0,false},
        {4,3,5,0,0,0,false}
    };

    int n = package.size();
    scheduling(package, n);

    float totalTAT = 0, totalWT = 0;

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : package) {
        cout << pr.pid << "\t" << pr.at << "\t" << pr.bt << "\t"
             << pr.ct << "\t" << pr.tat << "\t" << pr.wt << "\n";
        totalTAT += pr.tat;
        totalWT += pr.wt;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (totalTAT / n);
    cout << "\nAverage Waiting Time:    " << (totalWT / n) << "\n";

    return 0;
}
