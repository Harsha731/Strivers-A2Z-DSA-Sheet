/*
QUESTION:
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

APPROACH:
- This problem can be solved using dynamic programming.
- We need to find the count of square submatrices with all ones.
- Define a 2D DP array `dp` where dp[i][j] represents the side length of the largest square ending at (i, j).
- The base case is dp[i][0] = matrix[i][0] and dp[0][j] = matrix[0][j].
- Iterate through each cell (i, j) in the matrix starting from (1, 1).
- If matrix[i][j] is 1, update dp[i][j] as the minimum of (dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1.
- Add dp[i][j] to the `ans` variable to keep track of the total count of squares.
- Return the `ans`.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
- The space complexity is O(m * n) due to the dp array.
- Overall, the algorithm runs in O(m * n) time and O(m * n) space.

CODE:
*/

// dp[i][j] will signify for how many squares the rightmost bottom cell is (i, j).

// Memoization
int countSquaresHelper(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0; 
    if (dp[i][j] != -1) return dp[i][j]; 
    if (arr[i][j] == 0) return dp[i][j] = 0; 

    return dp[i][j] = 1 + min({countSquaresHelper(i - 1, j, arr, dp),
                               countSquaresHelper(i, j - 1, arr, dp),
                               countSquaresHelper(i - 1, j - 1, arr, dp)});
}

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); 
    int totalCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            totalCount += countSquaresHelper(i, j, arr, dp);
        }
    }

    return totalCount;
}
________________________________________________________

// Tabulation
int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}
_____________________________________

// Space Optimization
int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<int> prev(m, 0), curr(m, 0);
    int sum = 0;

    // Initialize the first row
    for (int j = 0; j < m; j++) {
        prev[j] = arr[0][j];
        sum += prev[j];
    }

    // Traverse the rest of the rows
    for (int i = 1; i < n; i++) {
        curr[0] = arr[i][0]; // Initialize the first column of the current row
        sum += curr[0];

        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                curr[j] = 0;
            } else {
                curr[j] = 1 + min({prev[j], prev[j - 1], curr[j - 1]});
            }
            sum += curr[j];
        }

        // Update `prev` for the next row
        prev = curr;
    }

    return sum;
}
