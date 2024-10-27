/*
QUESTION:
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Complexity Analysis:
- The time complexity of this solution is O(m + n), where m is the length of the needle and n is the length of the haystack.
- The space complexity is O(m + n) but can be reduced to O(n), where m is the length of the needle.

CODE:
*/

// The KMP algorithm uses a preprocessing step to build a partial match table (also known as the "prefix" table), 
// which helps in skipping unnecessary comparisons when a mismatch occurs.

// TC : O(M+N) and SC : O(1)

// a b c d e a b f a b c
// 0 0 0 0 0 1 2 0 1 2 3

// a a a a b a a c d
// 0 1 2 3 0 1 2 0 0 

// Abdul Bari example : a b a b c a b c a b a b a b d

// a b a b d
// 0 0 1 2 0

// If string was not matching at d, we don't go to first a
// instead, we go second a
// It is because this suffix have a number assigned to it, so it is also a prefix, we can try from there
// Even if it fails, we go to the start

// Abdul bari tells to compare i and j+1, but here we do i and j

// a a b a a a c  is the pattern
// 0 1 0 1 2 2 0
// Here, check the last 'a', it is not matching with the 'b', so we do len=lps[j-1], we check if this suffix is already present or not, if present we will go there
// 

// ** The intution is that, what if this suffix in pattern becomes a prefix for a new one in LPS array calculation

// Function to compute the prefix table (also called the longest prefix-suffix table)
void computeLPS(const string& pattern, int lps[]) {
    int length = 0;  // Length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0

    for (int i = 1; i < pattern.size(); i++) {
        while (length > 0 && pattern[i] != pattern[length]) {
            length = lps[length - 1]; // Fall back in the pattern.  Here the same j = lps[j-1] is happening which is another function too
        }
        if (pattern[i] == pattern[length]) {
            length++;
        }
        lps[i] = length; // Set the length for the current index
    }
}

// KMP search function
int strStr(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return 0; // Edge case

    int lps[m]; // Longest Prefix Suffix array
    computeLPS(pattern, lps); // Preprocess the pattern

    int i = 0; // Index for text - bigger one
    int j = 0; // Index for pattern - smaller one
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; // Match found
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Fall back in the pattern
            } else {
                i++; // Move to the next character in text
            }
        }
    }
    return -1; // Pattern not found
}
