/*
QUESTION:
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in the array. Find these two numbers.

Example:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and the smallest positive missing number is 1.

APPROACH:
To find the missing and repeating numbers in the given unsorted array, we can utilize the properties of summation and sum of squares. Let's denote the missing number as 'x' and the repeating number as 'y'.

1. Calculate the optimal sum 'optSum' using the formula: optSum = N * (N + 1) / 2, where N is the size of the array.
2. Calculate the optimal sum of squares 'opt2Sum' using the formula: opt2Sum = N * (N + 1) * (2 * N + 1) / 6.
3. Calculate the actual sum 'actSum' and actual sum of squares 'act2Sum' of the given array.
4. Find the difference between the optimal sum and the actual sum: xMinusY = optSum - actSum.
5. Find the difference between the optimal sum of squares and the actual sum of squares: x2MinusY2 = opt2Sum - act2Sum.
6. Calculate the sum of 'x' and 'y': xPlusY = x2MinusY2 / xMinusY.
7. Calculate 'x' and 'y' using the equations: x = (xPlusY + xMinusY) / 2 and y = xPlusY - x.

CODE:
*/

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array.
SPACE COMPLEXITY: O(1).
*/
