/*
QUESTION:
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example:
Input: k = 2, prices = [2, 4, 1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4 - 2 = 2.

APPROACH:
- This problem can be solved using dynamic programming.
- We need to keep track of the number of transactions completed so far (cap) and whether we are holding a stock or not on each day.
- Define a 3D DP array `dp` where dp[i][hold][cap] represents the maximum profit achievable starting from day i while holding or not holding a stock and having completed cap transactions.
- The base case is dp[n][0][0] = dp[n][0][1] = ... = dp[n][0][k] = dp[n][1][0] = ... = dp[n][1][k] = 0, where n is the number of days and k is the given limit of transactions.
- Iterate through each day i in reverse order.
- If holding a stock, we can either sell the stock or continue holding.
- If not holding a stock, we can either buy the stock or continue not holding.
- Return dp[0][0][0], which represents the maximum profit achievable starting from day 0 while not holding a stock and having completed 0 transactions.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n * k), where n is the number of days and k is the given limit of transactions.
- The space complexity is O(n * k) due to the dp array.
- Overall, the algorithm runs in O(n * k) time and O(n * k) space.

CODE:
*/

// Memoization

int maxi;
int fmemo(int i, int hold, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
    if(i == prices.size()) return 0;
    if(cap == maxi + 1) return 0;

    if(dp[i][hold][cap] != -1) return dp[i][hold][cap];

    if(hold){
        // sell 
        int a = prices[i] + fmemo(i + 1, 0, cap, prices, dp);
        // not sell
        int b = fmemo(i + 1, 1, cap, prices, dp);
        return dp[i][hold][cap] = max(a, b);
    }
    else{
        // buy
        int a = -prices[i] + fmemo(i + 1, 1, cap + 1, prices, dp);
        // not buy
        int b = fmemo(i + 1, 0, cap, prices, dp);
        return dp[i][hold][cap] = max(a, b);
    }
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    maxi = k;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return fmemo(0, 0, 0, prices, dp);
}
___________________________________________

// Tabulation

/*
dp[][][cap=0]  =  0
dp[n][][]      =  0
For selling situation, we consider, dp[][][cap] = dp[][][cap-1]	
There are cap+1 tables of n*2 size
*/
class Solution {
public:
    int maximumProfit(vector<int>& Arr, int n, int k) {
        // Creating a 3D DP array of size [n+1][2][k+1] initialized to 0
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Loop through the stock prices from the end to the beginning
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { // We can buy the stock
                        dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap], -Arr[ind] + dp[ind + 1][1][cap]);
                    }

                    if (buy == 1) { // We can sell the stock
                        dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap], Arr[ind] + dp[ind + 1][0][cap - 1]);
                    }
                }
            }
        }

        return dp[0][0][k];
    }

};
_____________________________________________

// Space optimization

int maxProfit(vector<int>& Arr, int n, int k) {
    // Create two arrays, 'ahead' and 'cur', to track the maximum profit at each step
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap], -Arr[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap], Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the 'ahead' array with the current values
        ahead = cur;
    }

    return ahead[0][k];
}
