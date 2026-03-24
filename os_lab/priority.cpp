#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, at, bt, pr, ct, tat, wt;
};

int main()
{
    vector<Process> p = {
        {1, 0, 8, 2, 0, 0, 0},
        {2, 1, 4, 1, 0, 0, 0},
        {3, 2, 9, 4, 0, 0, 0},
        {4, 3, 5, 3, 0, 0, 0}};

    int n = p.size();
    vector<int> done(n, 0);
    int completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;

    while (completed != n)
    {
        int idx = -1, max_pr = -1;
        for (int i = 0; i < n; i++)
        {
            if (!done[i] && p[i].at <= current_time)
            {
                if (p[i].pr > max_pr)
                {
                    max_pr = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == max_pr && idx != -1 && p[i].pid < p[idx].pid)
                {
                    idx = i;
                }
            }
        }
        if (idx != -1)
        {
            current_time += p[idx].bt;
            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            total_wt += p[idx].wt;
            total_tat += p[idx].tat;
            done[idx] = 1;
            completed++;
        }
        else
        {
            current_time++;
        }
    }

    cout << "PID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].pr << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << "\nAverage TAT: " << (total_tat / n);
    cout << "\nAverage WT: " << (total_wt / n) << endl;
}