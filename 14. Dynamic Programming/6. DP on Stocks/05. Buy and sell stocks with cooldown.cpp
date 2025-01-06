/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example:
Input: prices = [1, 2, 3, 0, 2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

APPROACH:
- This problem can be solved using dynamic programming.
- We need to keep track of whether we are holding a stock or not on each day.
- Define a 2D DP array `dp` where dp[i][hold] represents the maximum profit achievable starting from day i while holding or not holding a stock.
- The base case is dp[n][0] = dp[n][1] = 0, where n is the number of days.
- Iterate through each day i in reverse order.
- If holding a stock, we can either sell the stock or continue holding.
- If not holding a stock, we can either buy the stock or continue not holding.
- Return dp[0][0], which represents the maximum profit achievable starting from day 0 while not holding a stock.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n), where n is the number of days.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n) time and O(n) space.

CODE:
*/
// If you sell the stock, then be calm for 1 day.

int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp) {
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind >= n) return 0;
    
    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 2, 0, n, dp));
    }
    
    // Store the result in the DP array and return
    return dp[ind][buy] = profit;
}

int stockProfit(vector<int> &Arr) {
    int n = Arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    int ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}
__________________________

int stockProfit(vector<int> &Arr) {
    int n = Arr.size();
    // Create a 2D DP array with dimensions (n+2) x 2, initialized to 0
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}
__________________________

int stockProfit(vector<int> &Arr) {
    int n = Arr.size();
    
    // Initialize three arrays to track the maximum profit for buying and selling
    vector<int> cur(2, 0);       // Current maximum profit
    vector<int> front1(2, 0);    // Maximum profit one step ahead
    vector<int> front2(2, 0);    // Maximum profit two steps ahead
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        // Update the 'front1' and 'front2' arrays with current values
        front2 = front1;
        front1 = cur;
    }
    
    return cur[0]; // Return the maximum profit for buying.
}
