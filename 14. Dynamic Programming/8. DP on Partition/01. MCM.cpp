/*
QUESTION:
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:
Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explanation: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

APPROACH:
- This problem can be solved using dynamic programming.
- The dp[i][j] represents the minimum number of scalar multiplications required to compute the matrix chain multiplication of matrices from i to j.
- Iterate through the chain lengths from 2 to N (chain length of 2 means considering two matrices at a time).
- For each chain length, iterate through all possible starting matrices (i).
- For each starting matrix, calculate the cost of multiplying the matrices and update dp[i][j].
- Finally, return dp[1][N-1], which represents the minimum number of scalar multiplications needed for the entire matrix chain multiplication.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^3), where n is the length of the array arr.
- The space complexity is O(n^2) due to the dp array.
- Overall, the algorithm runs in O(n^3) time and O(n^2) space.

CODE:-
*/
/*
i starts from 1, as 0 is meaningless

If i==j, it means we are interested in a single matrix and no operation is required to multiply it so we return 0.

here, 1 refers to the 0,1
2 refers to 1,2
i.e, it refers to the single matrix

The for loops runs for { (1,1) (2,5) }, { (1,2) (3,5) }, { (1,3) (4,5) }, { (1,4) (5,5) }

For Tabulation, smaller subproblems are of length 2 first, then length 3, ...

There won't be space optimization code as it needs values from whole table, unlike only from the last row in some problems
*/

int calculateCost(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int temp = calculateCost(arr, i, k, dp) + calculateCost(arr, k + 1, j, dp) + (arr[k] * arr[i - 1] * arr[j]);
        ans = min(ans, temp);
    }

    dp[i][j] = ans;
    return ans;
}

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return calculateCost(arr, 1, N - 1, dp);
}

_____________________________________

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int l = 2; l < N; l++) {
        for (int i = 1; i < N - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int temp = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }

    return dp[1][N - 1];
}
