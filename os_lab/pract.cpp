#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, ct, tat, wt, queue;
    int remaining_bt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    cout << "Enter Arrival Time, Burst Time, and Queue Number (1 for High, 2 for Low):\n";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt >> p[i].queue;
        p[i].remaining_bt = p[i].bt;
    }

    int time = 0, completed = 0, tq = 2;
    sort(p.begin(), p.end(), [](Process a, Process b) { return a.at < b.at; });

    queue<int> q1, q2;
    cout << "\n--- Multi-Level Queue Scheduling ---\n";

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].at == time) {
                if (p[i].queue == 1)
                    q1.push(i);
                else
                    q2.push(i);
            }
        }

        if (!q1.empty()) {
            int idx = q1.front();
            q1.pop();

            int exec_time = min(tq, p[idx].remaining_bt);
            p[idx].remaining_bt -= exec_time;
            time += exec_time;

            for (int i = 0; i < n; i++) {
                if (p[i].at > time - exec_time && p[i].at <= time) {
                    if (p[i].queue == 1)
                        q1.push(i);
                    else
                        q2.push(i);
                }
            }

            if (p[idx].remaining_bt == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            } else
                q1.push(idx);
        }

        else if (!q2.empty()) {
            int idx = q2.front();
            q2.pop();

            time = max(time, p[idx].at);
            time += p[idx].bt;
            p[idx].remaining_bt = 0;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }

        else
            time++;
    }

    sort(p.begin(), p.end(), [](Process a, Process b) { return a.pid < b.pid; });

    double totalTAT = 0, totalWT = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\tQueue\n";
    for (auto &x : p) {
        cout << x.pid << "\t" << x.at << "\t" << x.bt << "\t" << x.ct << "\t" 
             << x.tat << "\t" << x.wt << "\t" << x.queue << "\n";
        totalTAT += x.tat;
        totalWT += x.wt;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time = " << totalTAT / n;
    cout << "\nAverage Waiting Time = " << totalWT / n << endl;
    return 0;
}
