/*
QUESTION:
Given two strings s and t, return the number of distinct subsequences of s which equals t.

APPROACH:
- The problem can be solved using dynamic programming.
- Let dp[i][j] represent the number of distinct subsequences of the first i characters of string s that match the first j characters of string t.
- If s[i] equals t[j], we have two choices: we can either include the current character (s[i]) in the subsequence, in which case we add dp[i-1][j-1] to our count, or we can exclude it and move on, so we add dp[i-1][j] to our count.
- If s[i] doesn't match t[j], we have no choice but to exclude s[i], so we add dp[i-1][j] to our count.
- Base cases: When j equals -1 (meaning we've matched all characters of t), return 1. When i equals -1 (meaning we've exhausted all characters of s), return 0.
- Return dp[n-1][m-1], where n is the length of s and m is the length of t.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n * m), where n is the length of string s and m is the length of string t.
- The space complexity is O(n * m) due to the dp array.
- Overall, the algorithm runs in O(n * m) time and O(n * m) space.

CODE:
*/

// Memoization
int fmemo(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    if (j < 0) return 1;
    if (i < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = fmemo(i - 1, j - 1, s, t, dp) + fmemo(i - 1, j, s, t, dp);
    else
        return dp[i][j] = fmemo(i - 1, j, s, t, dp);
}

// Tabulation
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: If `t` is an empty string, there's exactly one way to match it (by not picking any characters)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // Match or skip the character in `s`
            } else {
                dp[i][j] = dp[i - 1][j]; // Skip the character in `s`
            }
        }
    }

    return dp[n][m];
}

// Space Optimization
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    prev[0] = 1; // Base case: 1 way to form an empty string `t`

    for (int i = 1; i <= n; i++) {
        curr[0] = 1; // Base case: 1 way to form an empty string `t`
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1] + prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr; // Update the previous row to the current row
    }

    return prev[m];
}


int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fmemo(n - 1, m - 1, s, t, dp);
}
