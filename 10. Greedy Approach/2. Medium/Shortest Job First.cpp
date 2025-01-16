/*
Ready  Run   Complete
|-------|-------|
   WT      BT

WT + BT = TAT = CT - AT

1. Input:
   List of processes, each with:
      pid (Process ID)
      burst (Burst Time)
      arrival (Arrival Time)
2. Sort Processes:
   First by arrival time (earliest process arrives first).
   If arrival times are the same, by burst time (shortest burst first).
3. Scheduling:
   For each process:
      If currentTime is less than the process's arrival time, update it to the process's arrival time.
      Add the burst time of the process to currentTime.
   Compute:
      Completion Time (CT) = currentTime
      Turnaround Time (TAT) = CT - arrival
      Waiting Time (WT) = TAT - burst
4. Calculate the average turnaround time and average waiting time
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
