#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n], done[n];
    done[n] = {0};
    
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> at[i] >> bt[i];
    }

    int completed = 0, t = 0;
    while (completed < n) {
        int idx = -1, maxBT = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= t && bt[i] > maxBT) {
                maxBT = bt[i];
                idx = i;
            }
        }
        if (idx == -1) { t++; continue; }
        t += bt[idx];
        ct[idx] = t;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    double sumWT = 0, sumTAT = 0;
    cout << "PID\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
        sumWT += wt[i];
        sumTAT += tat[i];
    }
    cout << "Average WT: " << sumWT / n << "\n";
    cout << "Average TAT: " << sumTAT / n << "\n";
    return 0;
}
