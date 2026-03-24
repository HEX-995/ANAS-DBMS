#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;  
    int at;   
    int bt;   
    int ct;       
    int tat;  
    int wt; 
    bool completed; 
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

   
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].completed = false;
    }

    int completedCount = 0;
    int currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    while (completedCount < n) {
        int idx = -1;
        int minBT = INT_MAX;

       
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= currentTime) {
                if (p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
                else if (p[i].bt == minBT && p[i].at < p[idx].at) {
                    idx = i; 
                }
            }
        }

        if (idx != -1) {
            
            currentTime += p[idx].bt;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            totalTAT += p[idx].tat;
            totalWT += p[idx].wt;

            p[idx].completed = true;
            completedCount++;
        } 
        else {
            
            currentTime++;
        }
    }

    
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p) {
        cout << pr.pid << "\t" << pr.at << "\t" << pr.bt << "\t" 
             << pr.ct << "\t" << pr.tat << "\t" << pr.wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (totalTAT / n);
    cout << "\nAverage Waiting Time:    " << (totalWT / n) << "\n";

    return 0;
}
