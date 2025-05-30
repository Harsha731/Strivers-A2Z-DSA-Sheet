/*
QUESTION:
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.

APPROACH:
- The problem can be reduced to finding the minimum number of insertions needed to make a string a palindrome.
- We can find the Longest Common Subsequence (LCS) between the given string and its reverse.
- The length of the LCS gives us the length of the longest palindromic subsequence in the string.
- The minimum number of insertions required to make the string a palindrome is equal to the difference between the length of the string and the length of the LCS.
- Return this difference as the answer.

COMPLEXITY ANALYSIS:
- The time complexity of finding the LCS is O(n^2), where n is the length of the string.
- The space complexity is O(n^2) due to the dp array.
- Overall, the algorithm runs in O(n^2) time and O(n^2) space.

CODE:
*/

// Memoization
int fmemo(int i, int j, string &s, string &r, vector<vector<int>> &dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == r[j])
        return dp[i][j] = fmemo(i - 1, j - 1, s, r, dp) + 1;
    else
        return dp[i][j] = max(fmemo(i - 1, j, s, r, dp), fmemo(i, j - 1, s, r, dp));
}

// Tabulation
int ftab(int n, int m, string& s, string& r){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==r[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// Space Optimization
int fopt(int n, int m, string& s, string& r){
    vector<int> prev(m+1,0);
    for(int i=1; i<=n; i++){
        vector<int> curr(m+1,0);
        for(int j=1; j<=m; j++){
            if(s[i-1]==r[j-1]) curr[j] = prev[j-1]+1;
            else curr[j] = max(prev[j],curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int minInsertions(string s) {
    int n = s.size();
    string r = s;
    reverse(r.begin(), r.end());
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int lcs = fmemo(n - 1, n - 1, s, r, dp);
    return n - lcs;
}
