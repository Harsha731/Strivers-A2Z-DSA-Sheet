/*Your task is to implement the function atoi. The function takes a string (str) as an argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt functions.

Example 1:
Input:
str = "123"
Output: 123

Example 2:
Input:
str = "21a"
Output: -1
Explanation: Output is -1 as not all characters are digits.

Approach:

Whitespace Handling: The code starts by skipping leading whitespaces in the string.
Sign Handling: It then checks if the string starts with a '+' or '-' sign and updates the sign accordingly.
Digit Conversion: Using a loop, it converts consecutive digit characters to an integer and checks for overflow/underflow after each operation.
Overflow Handling: If the number exceeds INT_MAX or falls below INT_MIN, it returns the respective bounds.

Time Complexity: O(N), where N is the length of the string.
Space Complexity: O(N) for recustion stack space, O(1) for iteration

CODE:*/

Iteration :

class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        long long n=0;
        int i=0;

        while (s[i]==' '){
            i++;
        }

        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }


        for(int j=i;j<s.length();j++) {
            int m = s[j]-'0';
            if(m>=0 && m<=9) n = 10*n + m;
            else break;
            if (n * sign > INT_MAX) return INT_MAX;
            if (n * sign < INT_MIN) return INT_MIN;
        }
        return n * sign;
    }
};
________________________________________________________________

recursion :

class Solution {
public:
    long solve(string s, int sign, int i, long n){
        if(i==s.length()) return sign*n;
        int n1 = s[i]-'0';
        if(n1>=0 && n1<10){
            n = 10*n+n1;
            if(sign*n >= INT_MAX) return INT_MAX;
            if(sign*n <= INT_MIN) return INT_MIN;
            return solve(s, sign, i+1, n);
        }
        // if spaces are between, or any other charater is present
        return sign*n;
    }


    int myAtoi(string s) {
        int i=0,sign=1;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-') {
            sign=-1;
            i++;
        }
        else if(s[i]=='+') {
            i++;
        }
        return solve(s, sign, i, 0);
    }
};
