#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, at, bt, rt, ct, tat, wt;
};

int main()
{
    vector<Process> p = {
        {1, 0, 8, 0, 0, 0, 0},
        {2, 1, 4, 0, 0, 0, 0},
        {3, 2, 9, 0, 0, 0, 0},
        {4, 3, 5, 0, 0, 0, 0}};

    int n = p.size();
    for (int i = 0; i < n; i++)
        p[i].rt = p[i].bt;

    int completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;

    while (completed != n)
    {
        int idx = -1, max_rt = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && p[i].rt > 0)
            {
                if (p[i].rt > max_rt)
                {
                    max_rt = p[i].rt;
                    idx = i;
                }
                else if (p[i].rt == max_rt && idx != -1 && p[i].pid < p[idx].pid)
                {
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            p[idx].rt--;
            current_time++;
            if (p[idx].rt == 0)
            {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                total_wt += p[idx].wt;
                total_tat += p[idx].tat;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << "\nAverage TAT: " << (total_tat / n);
    cout << "\nAverage WT: " << (total_wt / n) << endl;

    return 0;
}
