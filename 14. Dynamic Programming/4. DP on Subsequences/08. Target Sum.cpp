/*
QUESTION:
Given an array 'nums' and an integer 'target', the task is to count 
the number of ways to make the sum of elements of one subset equal 
to 'target'.

Example:
Input: nums = [1, 1, 1, 1, 1], target = 3
Output: 5
Explanation: There are 5 ways to achieve the target sum: 
{1, 1, 1}, {1, 2}, {2, 1}, {1, 2}, {3}

APPROACH:
- The problem can be reduced to finding the count of subsets with a 
  given sum.
- Initialize dp[i][j] as the number of subsets with sum 'j' using 
  the first 'i' elements.
- Base cases:
  - dp[0][0] = 1 since an empty subset has a sum of 0.
  - dp[i][0] = 1 since there's always an empty subset.
- For each element 'nums[i]' and each possible sum 'j' from 1 to 'target':
  - dp[i][j] = dp[i-1][j] (not taking the current element)
  - if 'nums[i]' is less than or equal to 'j', then dp[i][j] += dp[i-1][j-nums[i]] (taking the current element)
- The required answer will be dp[n][target] where 'n' is the number 
  of elements in the array.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n * target), where 'n' 
  is the number of elements in the array.
- The space complexity is O(n * target) for the dp array.

CODE:
*/

// Memoization

// TC : O(N*K) : There are N*K states therefore at max ‘N*K’ new problems will be solved.
// SC : O(N*K) + O(N) : We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

int helper(int idx, int tgt, vector<int>& nums, vector<vector<int>>& memo) {
    if (idx == 0) {
        if (tgt == 0 && nums[0] == 0)      return 2;
        if (tgt == 0 || tgt == nums[0])       return 1;
        return 0;
    }   

    if (memo[idx][tgt] != -1)      return memo[idx][tgt];

    int exclude = helper(idx - 1, tgt, nums, memo);
    int include = 0;
    if (nums[idx] <= tgt)
        include = helper(idx - 1, tgt - nums[idx], nums, memo);

    return memo[idx][tgt] = (exclude + include);
}

int findWays(int n, int tgt, vector<int>& nums) {
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
    }

    if (totalSum - tgt < 0)       return 0;
    if ((totalSum - tgt) % 2 == 1)       return 0;

    int s2 = (totalSum - tgt) / 2;
    vector<vector<int>> memo(n, vector<int>(s2 + 1, -1));
    return helper(n - 1, s2, nums, memo);
}
__________________________________

// Tabulation

const int mod = 1e9 + 7;

int countWays(vector<int>& nums, int targetSum) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, 0));

    dp[0][0] = nums[0] == 0 ? 2 : 1;
    if (nums[0] <= targetSum && nums[0] != 0) dp[0][nums[0]] = 1;

    for (int i = 1; i < n; ++i) {
        for (int sum = 0; sum <= targetSum; ++sum) {
            dp[i][sum] = (dp[i - 1][sum] + (nums[i] <= sum ? dp[i - 1][sum - nums[i]] : 0)) % mod;
        }
    }
    return dp[n - 1][targetSum];
}

int findTargetSumWays(int n, int target, vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum < target || (totalSum - target) % 2 != 0) return 0;
    return countWays(nums, (totalSum - target) / 2);
}
______________________________________

// Space optimization

const int mod = 1e9 + 7;

int calculateWays(vector<int>& nums, int targetSum) {
    int n = nums.size();
    vector<int> prev(targetSum + 1, 0);

    if (nums[0] == 0)    prev[0] = 2;
    else      prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= targetSum)     prev[nums[0]] = 1;

    for (int i = 1; i < n; i++) {
        vector<int> cur(targetSum + 1, 0);
        for (int sum = 0; sum <= targetSum; sum++) {
            int notPicked = prev[sum];
            int picked = 0;
            if (nums[i] <= sum)
                picked = prev[sum - nums[i]];
            cur[sum] = (notPicked + picked) % mod;
        }
        prev = cur;
    }
    return prev[targetSum];
}

int targetSumWays(int n, int target, vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum < target || (totalSum - target) % 2 != 0)
        return 0;
    return calculateWays(nums, (totalSum - target) / 2);
}

