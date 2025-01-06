/*
QUESTION:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

APPROACH:
- This problem can be solved using dynamic programming.
- Let dp[i] represent the length of the longest increasing subsequence ending at index i.
- For each element at index i, we iterate through all the previous indices (prev) from 0 to i-1
- If nums[prev] is smaller than nums[i], it means we can extend the increasing subsequence ending at prev by including nums[i].
- We update dp[i] as max(dp[prev] + 1, dp[i]).
- Initialize a variable ans to keep track of the maximum value in dp.
- Return ans as the length of the longest increasing subsequence.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the input array nums.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/

// We can write in reverse also for each method

// Memoization
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));    
    return getAns(arr, n, 0, -1, dp);
}
_____________________________________

// Tabulation

int longestIncreasingSubsequence(int arr[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Process the table from bottom to top
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--) {
            int notTake = dp[ind + 1][prev_index + 1];
            
            int take = 0;
            if (prev_index == -1 || arr[ind] > arr[prev_index]) {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev_index + 1] = max(notTake, take);
        }
    }
    return dp[0][0];
}
___________________________

// Space Optimization

class Solution {
public:

int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    // Process from bottom to top
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--) {
            int notTake = next[prev_index + 1];
            
            int take = 0;
            if (prev_index == -1 || arr[ind] > arr[prev_index]) {
                take = 1 + next[ind + 1];
            }
            curr[prev_index + 1] = max(notTake, take);
        }
        next = curr;
    }
    return next[0];
}

};
