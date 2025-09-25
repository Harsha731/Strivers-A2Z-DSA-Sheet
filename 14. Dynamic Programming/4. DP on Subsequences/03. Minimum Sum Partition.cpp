/*
QUESTION:
Given an array arr of size n containing non-negative integers,
the task is to divide it into two sets S1 and S2 such that the absolute
difference between their sums is minimum and find the minimum difference

Example 1:
Input: N = 4, arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

APPROACH:
- Calculate the sum of all elements in the array.
- Initialize a 2D dp array of size n x (sum + 1) to store if it is possible to achieve a sum 's' using the first 'i' elements.
- Initialize dp[i][0] to true, since an empty subset can have a sum of 0.
- For each element 'arr[i]' and each possible sum 's' from 1 to 'sum':
  - Check if it's possible to achieve a sum of 's' using the first 'i-1' elements, or using 's - arr[i]' and the first 'i-1' elements.
  - Update dp[i][s] accordingly.
- Iterate through the dp array for the last row and find the minimum absolute difference between the sum 's' and 'totalSum - s' for which dp[n-1][s] is true.

COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n * sum), where 'n' is the number of elements and 'sum' is the sum of all elements.
- The space complexity is O(n * sum) for the dp array.

CODE:
*/

// Memoization
/*
Time Complexity (TC): The TC is O(n . totalSum), where n is the number of elements and totalSum is the sum of all
elements, as we solve n · totalSum subproblems.

Space Complexity (SC): The SC is O(n . totalSum), due to the memoization table storing results for all subproblems. The
recursion stack uses O(n) space, which is dominated by the memoization table.
*/
int solve(int i, int sumA, int sumB, vector<int>& nums, vector<vector<int>>& dp) {
    // Base case: If all elements are processed, return the absolute difference
    if (i == nums.size()) {
        return abs(sumA - sumB);
    }

    if (dp[i][sumA] != -1) {
        return dp[i][sumA];
    }

    // Include the current element in subset A
    int includeInA = solve(i + 1, sumA + nums[i], sumB, nums, dp);

    // Include the current element in subset B
    int includeInB = solve(i + 1, sumA, sumB + nums[i], nums, dp);

    return dp[i][sumA] = min(includeInA, includeInB);
}

int minSubsetSumDifference(vector<int>& nums, int n) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
    return solve(0, 0, 0, nums, dp);
}
_________________________________________

// Tabulation

int minSubsetSumDifference(vector<int>& nums, int n) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0); // Total sum of all elements

    // dp[i][j] = true if sum j can be formed using first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Base case: sum 0 is always possible with 0 elements
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            if (nums[i - 1] <= j) {
                // Include or exclude current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                // Cannot include current element, just take previous state
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Find minimum difference by checking all possible subset sums ≤ totalSum/2
    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n][s1]) { // If sum s1 is possible
            int s2 = totalSum - s1;          // Other subset sum
            minDiff = min(minDiff, abs(s2 - s1)); // Update min difference
        }
    }

    return minDiff;
}
/
_________________________________________

// Space Optimization

int minSubsetSumDifference(vector<int>& nums, int n) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // prev[j] = whether sum j is possible using processed elements so far
    vector<bool> prev(totalSum + 1, false);
    prev[0] = true;  // sum 0 is always possible

    // Fill DP array
    for (int i = 0; i < n; i++) {
        vector<bool> curr(totalSum + 1, false);
        curr[0] = true; // sum 0 is always possible
        for (int j = 1; j <= totalSum; j++) {
            if (nums[i] <= j)
                curr[j] = prev[j] || prev[j - nums[i]]; // include or exclude
            else
                curr[j] = prev[j];                     // cannot include
        }
        prev = curr; // move to next element
    }

    // Find minimum difference
    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (prev[s1]) {          // if sum s1 is possible
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }

    return minDiff;
}
