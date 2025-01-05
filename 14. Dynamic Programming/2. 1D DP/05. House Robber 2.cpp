/*
QUESTION:-
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Approach:
1. Since the houses are arranged in a circle, the robber cannot rob the first and last house together as they are adjacent.
2. To solve this problem, we can divide it into two subproblems: one where the robber robs from the first house to the second-last house (excluding the last house), and another where the robber robs from the second house to the last house (excluding the first house).
3. We can use dynamic programming with memoization to calculate the maximum amount of money that can be robbed in each subproblem.
4. We define a helper function fmemo(e, i, nums, dp) that calculates the maximum amount of money that can be robbed from the e-th to the i-th house using memoization.
5. The function checks if the maximum amount for the i-th house is already calculated and stored in the dp array. If yes, it returns the value from dp.
6. Otherwise, it calculates the maximum amount by considering two options:
   a) Rob the current house and add the money with the maximum amount from the (i-2)th house (since adjacent houses cannot be robbed).
   b) Skip the current house and take the maximum amount from the (i-1)th house.
7. The base case is when i is less than e, in which case the function returns 0 as there are no houses to rob.
8. In the main function rob(nums), we first check if there is only one house. If yes, the robber can only rob that house, so we return the amount in that case.
9. Otherwise, we create a dp array of size n initialized with -1 and call the fmemo function twice: one for robbing from the first to the second-last house and the other for robbing from the second to the last house.
10. Finally, we return the maximum amount from the two subproblems, which gives the maximum amount the robber can rob without alerting the police.

Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating the maximum amount for each house only once and storing it in the dp array.
- The space complexity is also O(n) to store the dp array.
*/

// Memoization
int robMemo(int start, int end, vector<int>& nums, vector<int>& dp) {
    if (end < start)
        return 0;

    if (end == start)
        return dp[end] = nums[end];

    if (dp[end] != -1)
        return dp[end];

    int pick = nums[end] + robMemo(start, end - 2, nums, dp);
    int skip = robMemo(start, end - 1, nums, dp);
    return dp[end] = max(pick, skip);
}

// Tabulation
int robTab(int start, int end, vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[start] = nums[start];
    for (int i = start + 1; i <= end; i++) {
        int pick = nums[i];
        if (i - 2 >= start)
            pick += dp[i - 2];
        int skip = dp[i - 1];
        dp[i] = max(pick, skip);
    }
    return dp[end];
}

// Space Optimization
int robOpt(int start, int end, vector<int>& nums) {
    int prev1 = nums[start], prev2 = 0, curr = 0;
    for (int i = start + 1; i <= end; i++) {
        int pick = nums[i];
        if (i - 2 >= start)
            pick += prev2;
        int skip = prev1;
        curr = max(pick, skip);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> dp(n, -1);
    int case1 = robMemo(1, n - 1, nums, dp); // Rob from 2nd to last house
    dp.assign(n, -1);
    int case2 = robMemo(0, n - 2, nums, dp); // Rob from 1st to 2nd-last house
    return max(case1, case2);
}
