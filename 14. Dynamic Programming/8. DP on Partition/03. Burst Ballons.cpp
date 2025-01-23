/*
QUESTION:
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums.
You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example:
Input: nums = [3, 1, 5, 8]
Output: 167
Explanation:
nums = [3, 1, 5, 8] --> [3, 5, 8] --> [3, 8] --> [8] --> []
coins = 3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167.

APPROACH:
- This problem can be solved using dynamic programming.
- Define a 2D DP array `dp` where dp[i][j] represents the maximum coins collected by bursting balloons between indices i and j.
- Iterate over the stick lengths from length 2 to the length of nums - 1.
- For each subarray length, iterate through all possible starting indices (i).
- Calculate the maximum coins collected by bursting balloons in the subarray between i and j, and update the dp array.
- Finally, return dp[1][n - 2], which represents the maximum coins collected by bursting all the balloons.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^3), where n is the length of the nums array.
- The space complexity is O(n^2) due to the dp array.
- Overall, the algorithm runs in O(n^3) time and O(n^2) space.

CODE:
*/

int fmemo(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
    if(j < i) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = -1e9;
    // the main curx is we are finding the last ballon remaining instead of the one bursting so that both sub problems remain independent
    for(int k = i; k <= j; k++){
        int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + fmemo(i, k - 1, nums, dp) + fmemo(k + 1, j, nums, dp);
        ans = max(ans, coins);
    }
    return dp[i][j] = ans;
}

int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    int i = 1, j = n - 2;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return fmemo(i, j, nums, dp);
}
___________________________________________________

// Tabulation
// No Space Optimization here
// We assume the 'ind' ballon is burst at the end, so we do these 2 first - dp(i, ind-1) and dp(ind+1, j)
// We calculate like this for every (i, j) pair

int maxCoins(vector<int> &nums) {
    int n = nums.size();
    
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {        // We can put j=i to n instead
            if (i > j) continue;
            int maxi = INT_MIN;
            
            // Iterate through each possible balloon to burst (last)
            for (int ind = i; ind <= j; ind++) {
                // Calculate the coins obtained by bursting the ind-th balloon (last)
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                
                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];                
                maxi = max(maxi, coins + remainingCoins);
            }
            
            dp[i][j] = maxi;
        }
    }
    
    return dp[1][n];
}

