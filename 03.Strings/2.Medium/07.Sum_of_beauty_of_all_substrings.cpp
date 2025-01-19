/*Question:

The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

Given a string `s`, you need to calculate the sum of beauty for all of its substrings. The beauty of a substring is 
defined as the difference between the highest and lowest frequency of any character in the substring.

Write a function `beautySum` that takes a string `s` as input and returns the sum of beauty for all substrings.

Example:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Input: s = "aabcbaa"
Output: 17

Approach:

Initialize ans = 0 to store the total beauty sum.
Loop i from 0 to n-1 (start of substrings):
   Initialize char_count[26] to track character frequencies.
Loop j from i to n-1 (end of substrings):
   Update char_count[s[j] - 'a'].
   Find max and min non-zero values in char_count.
   Add max - min to ans.
Return ans.

We can't do the same for max for 1,2,2,2,2 after doing 2 to 3, we compare last max and the element increased
But for min, we need to check all the vector once

CODE:-
*/
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> char_count(26, 0);
            int max_freq = 0;

            for (int j = i; j < n; j++) {
                // Update frequency of the current character
                char_count[s[j] - 'a']++;

                // Update max frequency
                max_freq = max(max_freq, char_count[s[j] - 'a']);

                // Find min frequency (non-zero) on the fly
                int min_freq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (char_count[k] > 0) {
                        min_freq = min(min_freq, char_count[k]);
                    }
                }

                // Add beauty (max - min) to the result
                ans += max_freq - min_freq;
            }
        }

        return ans;
    }
};


/*
Time complexity :- for generating all substrings is O(n^2)
Space complexity :- O(1)
*/
