/*
QUESTION:
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example:
Input: arr = [1, 15, 7, 9, 2, 5, 10], k = 3
Output: 84
Explanation: arr becomes [15, 15, 15, 9, 10, 10, 10]

APPROACH:
- This problem can be solved using dynamic programming.
- Define a 1D DP array `dp` where dp[i] represents the largest sum of the array after partitioning from index i to the end.
- Iterate through each index i of the array in reverse order.
- For each index i, iterate through all possible partition lengths from 1 to k.
- Calculate the maximum sum for the current partition, which is the maximum element within the partition multiplied by the length of the partition.
- Update dp[i] with the maximum value among all possible partition scenarios.
- Finally, return dp[0], which represents the largest sum of the array after partitioning.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n * k), where n is the length of the array.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n * k) time and O(n) space.

CODE:
*/
___________________________________________
/*
In memorization, 
'maxi' means the maximum element in that subarray of size at most k, 
'maxAns' is the maximum sum of all by considering the all possibilities of partitioning 

TC is O(N*K)
SC is O(N) + O(N)
for dp array and for stack space

arr = [1,15,7,9,2,5,10], k = 3
[1, 15, 7 | 9 | 2, 5, 10]. 
[15,15,15,9,10,10,10] 
sum is 84

This is similar to the Palindrome partitioing II
*/

int f(int ind, vector<int> &num, int k, vector<int> &dp) {
    int n = num.size();

    if (ind == n) return 0;

    if (dp[ind] != -1) return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}
_____________________________________

int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    
    vector<int> dp(n + 1, 0);
    
    // Iterate through the array from right to left.
    for (int ind = n - 1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
        // Loop through the next k elements (or remaining elements if k is smaller).
        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    
    return dp[0];
}
