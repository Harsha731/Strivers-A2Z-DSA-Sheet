/*
Ready  Run   Complete
|-------|-------|
   WT      BT

WT + BT = TAT = CT - AT
*/

struct Process {
    int pid;       // Process ID
    int burst;     // Burst Time
    int arrival;   // Arrival Time
};

// Comparator function to sort by arrival time, then by burst time
bool compare(Process a, Process b) {
    if (a.arrival == b.arrival)
        return a.burst < b.burst;
    return a.arrival < b.arrival;
}

void SJF(vector<Process> &processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end(), compare); // Sort processes by arrival and burst time

    vector<int> waitingTime(n), turnaroundTime(n), completionTime(n);
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival) {
            currentTime = processes[i].arrival;
        }
        currentTime += processes[i].burst;
        completionTime[i] = currentTime;
        turnaroundTime[i] = completionTime[i] - processes[i].arrival;
        waitingTime[i] = turnaroundTime[i] - processes[i].burst;
    }

    // Calculate average Turnaround and Waiting Time
    double avgTurnaround = accumulate(turnaroundTime.begin(), turnaroundTime.end(), 0.0) / n;
    double avgWaiting = accumulate(waitingTime.begin(), waitingTime.end(), 0.0) / n;
}
