/*
QUESTION:
Given an integer N, print all the divisors of N in ascending order.

Example:
Input: 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely divisible by 1, 2, 4, 5, 10, and 20.

APPROACH:
To print all the divisors of a number N, we can iterate from 1 to sqrt(N) and check if each number divides N.
1. Initialize an empty vector `temp` to store the divisors greater than sqrt(N).
2. Iterate from 1 to sqrt(N):
   - If `i` divides `N` (i.e., N % i == 0):
     - Print `i`.
     - If N/i != i, it means N/i is a divisor. Add it to `temp`.(we are checking N/i != i because 6*6 = 36 so our divisor should be 1 time 6)
3. Reverse the elements in `temp` vector.
4. Print all the elements in `temp`.
5. The divisors of N will be printed in ascending order.

CODE:*/
void print_divisors(int n) {
    vector<int> temp;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (n / i != i)
                temp.push_back(n / i);
        }
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";
}

sum = 0, cnt = 0
while (sum + divisor <= dividend) {
	cnt = cnt + 1;
	sum += divisor;
}
return cnt;

TLE will come

TC is O(log2N * log2N)

-2^31, when we write abs(-2^31), it will give error, so, we write long long

int divideTwoInteger(int dividend, int divisor) {
    if (dividend == divisor)
        return 1;

    bool isNegative = ((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0));

    int ans = 0;
    int a = abs(dividend);
    int b = abs(divisor);

    while (a >= b) {
        // at each stage we will find the greatest power of 2 which is smaller than the dividend
int q = 1;
while (a > (b << q))
	q++;
ans += (1 << (q - 1));
a -= (b << (q - 1));
    }

    return (isNegative) ? -ans : ans;
}

// Time Complexity: O(sqrt(N))
// Space Complexity: O(sqrt(N)) (excluding the space required for the output vector)
