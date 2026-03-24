#include <iostream>
#include <algorithm>
using namespace std;


struct Process {
    int pid;
    int at;
    int bt;  
    int ct;  
    int tat;  
    int wt;   
};

bool compareArrival(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    
    Process p[] = {
        {1, 0, 5},  
        {2, 1, 3},
        {3, 2, 8}
    };

    int n = sizeof(p) / sizeof(p[0]);

  
    sort(p, p + n, compareArrival);

   
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at; 
        }
        currentTime += p[i].bt;
        p[i].ct = currentTime; 
    }


    double totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at; 
        p[i].wt = p[i].tat - p[i].bt; 

        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    cout << "\nAverage Turnaround Time = " << (totalTAT / n);
    cout << "\nAverage Waiting Time = " << (totalWT / n) << "\n";

    return 0;
}
