/*
QUESTION:
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example:
Input: prices = [7, 1, 5, 3, 6, 4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5 - 1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6 - 3 = 3.
Total profit is 4 + 3 = 7.

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

/*
Buy on 1 day, sell on another day, but only one at a time can be holded
Use a n*2 DP vector for 0 : not holding and 1 : holding

** We are interested in making this problem into subproblems, and the small sub problem is at the end (n-1)
And we need answer at the top level. It is at the start for both recursion / tabulation

** 1 means we are holding a stock, so we can sell if we want

1) Memoization :
TC: O(N*2) : There are N*2 states therefore at max ‘N*2’ new problems will be solved and we are running 
 a for loop for ‘N’ times to calculate the total sum
SC: O(N*2) + O(N) : We are using a recursion stack space(O(N)) and a 2D array ( O(N*2)).
*/

int fmemo(int i, int hold, vector<int>& prices, vector<vector<int>>& dp){
    if(i == prices.size()) return 0;

    if(dp[i][hold] != -1) return dp[i][hold];

    if(hold){
        // sell 
        int a = prices[i] + fmemo(i + 1, 0, prices, dp);
        // not sell
        int b = fmemo(i + 1, 1, prices, dp);
        return dp[i][hold] = max(a, b);
    }
    else{
        // buy
        int a = -prices[i] + fmemo(i + 1, 1, prices, dp);
        // not buy
        int b = fmemo(i + 1, 0, prices, dp);
        return dp[i][hold] = max(a, b);
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fmemo(0, 0, prices, dp);
}
_________________________________________________

// Tabulation

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 
    // dp[i][0] = max profit at i when not holding, dp[i][1] = max profit when holding

    // Bottom-up calculation
    for (int i = n - 1; i >= 0; --i) {
        for (int hold = 0; hold <= 1; ++hold) {
            if (hold == 1) {
                // If holding a stock, we can sell or skip
                dp[i][hold] = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
            } else {
                // If not holding a stock, we can buy or skip
                dp[i][hold] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
            }
        }
    }

    return dp[0][0]; // Starting at index 0 with no stock in hand
}
_____________________________

// Space Optimization

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0); // Space-optimized arrays

    // Bottom-up calculation
    for (int i = n - 1; i >= 0; --i) {
        for (int hold = 0; hold <= 1; ++hold) {
            if (hold == 1) {
                // If holding a stock, we can sell or skip
                curr[hold] = max(prices[i] + ahead[0], ahead[1]);
            } else {
                // If not holding a stock, we can buy or skip
                curr[hold] = max(-prices[i] + ahead[1], ahead[0]);
            }
        }
        ahead = curr; // Update ahead for the next iteration
    }

    return ahead[0]; // Starting at index 0 with no stock in hand
}
