/*
QUESTION:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

APPROACH:
- This problem can be solved using dynamic programming.
- Define a 1D DP array `dp` where dp[i] represents the minimum cuts needed for a palindrome partitioning of s starting from index i.
- Iterate through each index i of the string.
- For each index i, iterate through all possible ending indices j such that j is in the range [i, n).
- Check if the substring from index i to j is a palindrome. If yes, update the dp[i] value by taking the minimum of its current value and dp[j + 1] + 1.
- Finally, return dp[0] - 1, which represents the minimum cuts needed for a palindrome partitioning of the entire string.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(n^2), where n is the length of the string.
- The space complexity is O(n) due to the dp array.
- Overall, the algorithm runs in O(n^2) time and O(n) space.

CODE:
*/
__________________________________________
/*
The approach we are using is called as front partition

An extra partition is made at the end like a | b | c | d | <-
So, our actual answer will be (partitions - 1).

There are N characters and for each i to N-1 are called in for loop
So, O(N^2) TC and 
O(N) + O(N) SC for dp array and for stack space too

Tabulation :
1) First of all, we handle the base case. If (i == n) we return 0. To cover this case we can initialize the entire dp array with 0.
2) Here, as we are checking dp[j+1]  every time, the function will give a runtime error if j = n-1. To avoid this, we will take the array size as n+1 instead of n.
3) Next, memoization is a top-down approach, whereas tabulation is bottom-up. Our changing parameter i will change in opposite directions, i.e i will change from n-1->0.
4) Next, we copy down the recursive logic(recurrence) inside the loop.

https://takeuforward.org/data-structure/palindrome-partitioning-ii-front-partition-dp-53/

check out the memorization and tabulation codes

Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.
s = "bababcbadcede"
bab | abcba | d | c | ede
answer is 4

We are taking the min of all possible values for various j for each i
Answer exists for sure, as each letter can be seperate and n-1 is max answer
*/
_____________________________________________________________________

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minPartitions(int i, int n, string &str, vector<int> &dp) {
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

// Don't remove this
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    // Subtract 1 as it counts partitions, not cuts.
    return minPartitions(0, n, str, dp) - 1;
}
___________________________________________________

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    // Loop through the string in reverse order.
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}
