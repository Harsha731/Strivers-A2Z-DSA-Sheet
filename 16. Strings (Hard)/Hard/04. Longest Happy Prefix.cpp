/*
QUESTION:
A string is called a happy prefix if it is a non-empty prefix that is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefixes excluding itself ("l", "le", "lev", "leve") and suffixes ("l", "el", "vel", "evel"). The largest prefix that is also a suffix is "l".

Approach:

We can add letters at the front only
In the worst case, we need to add n-1 letters at the front
KMP algo, do precomputation of LPS array

aacecaaa$aaacecaa	
The last a gives LPS[] = 7. So, the first 7 letters are in palindrome, The next are not. So, do s.substr(7) and keep that at front by reversing

- We can solve this problem using the KMP (Knuth-Morris-Pratt) algorithm.
- First, we calculate the LPS (Longest Prefix Suffix) array for the given string s.
- The last value in the LPS array, lps[n-1], represents the length of the longest prefix that is also a suffix.
- We extract the corresponding substring from s and return it as the longest happy prefix.

Complexity Analysis:
- The time complexity of this solution is O(n), where n is the length of the string s.
- The space complexity is O(n) to store the LPS array.

CODE:
*/
class Solution {
public:
vector<int> computeLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    int length = 0;  // Length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0

    for (int i = 1; i < n; i++) {
        while (length > 0 && pattern[i] != pattern[length]) {
            length = lps[length - 1]; // Fall back in the pattern
        }
        if (pattern[i] == pattern[length]) {
            length++;
        }
        lps[i] = length; // Set the length for the current index
    }
    return lps;
}


string longestPrefix(string s) {
    int n = s.size();
    vector<int> lps = computeLPS(s);
    int length = lps[n - 1]; // Length of the longest prefix that is also a suffix
    return s.substr(0, length);
}
};

