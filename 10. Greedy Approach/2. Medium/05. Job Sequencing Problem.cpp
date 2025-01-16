/*
Question:
Given a set of N jobs where each job 'i' has a deadline and profit associated with it. Each job takes 1 unit of time to complete, 
and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its 
deadline. Find the number of jobs done and the maximum profit.

Example:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with a maximum profit of 60 (20+40).

Approach:

1. Sort Jobs:
   Sort all jobs in descending order of profit to prioritize higher-profit jobs.
2. Allocate Slots:
   Initialize an array (slot) to track available time slots (size n).
3. Iterate through the sorted jobs:
   For each job, find the latest available time slot (≤ its deadline).
   If a free slot is found, assign the job to that slot and mark it as filled.
4. Calculate Total Profit:
   Accumulate the profit of all scheduled jobs.

Complexity Analysis:
- The time complexity of this approach is O(NlogN), where N is the number of jobs.
- This is due to the sorting operation on the 'jobs' vector based on profits.
- The space complexity is O(N) as we use additional vectors to store the jobs and deadlines.


Notes :-
We sort all the jobs based on profit, here each task takes 1 unit of time
We can keep the task in the places from 0 to min(n, deadline) - 1. We try to keep any task in the max possible time
So, that other tasks having faster deadlines can be done can be benefitted by this task
We can remove result vector if we don't want to know which task is assigned at what time
Here, we check from deadline-1 to 0. It is because if the deadline is 9, it means we can assign the task at t=8 and not at t=9
Code:
*/


// Structure to represent a job
struct Job {
    int id;       // Job ID
    int deadline; // Deadline for the job
    int profit;   // Profit if the job is completed
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit job sequence
void jobSequencing(vector<Job> &jobs, int n) {
    // Step 1: Sort all jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Create an array to store the result (sequence of jobs)
    vector<int> result(n, -1); // -1 indicates the slot is free
    vector<bool> slot(n, false); // Slot availability tracker

    int totalProfit = 0;

    // Step 3: Iterate over sorted jobs
    for (int i = 0; i < jobs.size(); i++) {
        // Try to schedule the job in the last possible free slot (<= deadline)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) { // If the slot is free
                result[j] = jobs[i].id; // Assign the job ID to the slot
                slot[j] = true;         // Mark the slot as filled
                totalProfit += jobs[i].profit; // Add the profit
                break;
            }
        }
    }

    // Step 4: Print the job sequence
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            cout << result[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

