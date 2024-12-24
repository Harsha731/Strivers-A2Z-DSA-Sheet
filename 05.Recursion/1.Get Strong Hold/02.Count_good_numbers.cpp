/*QUESTION:
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303

Approach:
- modular exponentiation

Time Complexity: O(logn)
Space Complexity: O(1) 

CODE:*/

method 1 )

long long power(long long n, long long k) {
        long long result = 1;
        while (k > 0) {
            if (k & 1) { // Check if the last bit of k is 1 (k is odd)
                result = (result * n) % mod;
            }
            n = (n * n) % mod; // Square the base
            k >>= 1; // Right shift k to divide it by 2
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) >> 1; // Divide (n + 1) by 2 using right shift
        long long odd = n >> 1;       // Divide n by 2 using right shift
        long long t = (power(5, even) * power(4, odd)) % mod;
        return t;
    }
