#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, remaining_bt, ct, tat, wt, queueLevel;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].remaining_bt = p[i].bt;
        p[i].queueLevel = 1;
    }
    sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.at < b.at; });
    queue<int> q1, q2, q3;
    int time = 0, completed = 0;
    vector<bool> inQueue(n, false);
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && !inQueue[i] && p[i].remaining_bt > 0) {
                q1.push(i);
                inQueue[i] = true;
            }
        }
        if (!q1.empty()) {
            int i = q1.front(); q1.pop();
            int tq = 4;
            int exec_time = min(tq, p[i].remaining_bt);
            time += exec_time;
            p[i].remaining_bt -= exec_time;
            for (int j = 0; j < n; j++) {
                if (p[j].at <= time && !inQueue[j] && p[j].remaining_bt > 0) {
                    q1.push(j);
                    inQueue[j] = true;
                }
            }
            if (p[i].remaining_bt == 0) {
                p[i].ct = time;
                completed++;
            } else {
                p[i].queueLevel = 2;
                q2.push(i);
            }
        }
        else if (!q2.empty()) {
            int i = q2.front(); q2.pop();
            int tq = 8;
            int exec_time = min(tq, p[i].remaining_bt);
            time += exec_time;
            p[i].remaining_bt -= exec_time;
            for (int j = 0; j < n; j++) {
                if (p[j].at <= time && !inQueue[j] && p[j].remaining_bt > 0) {
                    q1.push(j);
                    inQueue[j] = true;
                }
            }
            if (p[i].remaining_bt == 0) {
                p[i].ct = time;
                completed++;
            } else {
                p[i].queueLevel = 3;
                q3.push(i);
            }
        }
        else if (!q3.empty()) {
            int i = q3.front(); q3.pop();
            time += p[i].remaining_bt;
            p[i].remaining_bt = 0;
            p[i].ct = time;
            completed++;
            for (int j = 0; j < n; j++) {
                if (p[j].at <= time && !inQueue[j] && p[j].remaining_bt > 0) {
                    q1.push(j);
                    inQueue[j] = true;
                }
            }
        } else {
            time++;
        }
    }
    double avgTAT = 0, avgWT = 0;
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        x.tat = x.ct - x.at;
        x.wt = x.tat - x.bt;
        avgTAT += x.tat;
        avgWT += x.wt;
        cout << "P" << x.pid << "\t" << x.at << "\t" << x.bt << "\t" << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }
    cout << "\nAverage Turnaround Time: " << avgTAT / n;
    cout << "\nAverage Waiting Time: " << avgWT / n << endl;
    return 0;
}
