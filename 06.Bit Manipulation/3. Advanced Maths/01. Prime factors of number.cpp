/*
QUESTION:
Given a number N, find its unique prime factors in increasing order.

Example:
Input: N = 100
Output: 2 5
Explanation: 2 and 5 are the unique prime factors of 100.

APPROACH:
To find the unique prime factors of a number N, we can iterate from 2 to sqrt(N) and check if each number divides N.
1. Initialize an empty vector `ans` to store the prime factors.
2. Iterate from 2 to sqrt(N):
   - If `i` divides `N` (i.e., N % i == 0):
     - Add `i` to `ans`.
     - Divide `N` by `i` until it is no longer divisible by `i`.
3. If `N` is still greater than 1, it means that `N` itself is a prime factor. Add it to `ans`.
4. Return `ans`.

CODE:*/
// Function to check if a number is prime
bool prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// method 1

vector<int> findPrimeFactorsMethod1(int n) {
    vector<int> list;

    // TC is O(N * root(N))
    // SC depends on input, as we are not using any space for space but only for output list
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (prime(i)) list.push_back(i);
        }
    }

    return list;
}

// method 2

vector<int> findPrimeFactorsMethod2(int n) {
    vector<int> list;

    // TC is O(root(N) * root(N))
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (prime(i)) list.push_back(i);
            if (n / i != i) { // not a perfect square like 6*6 = 36
                if (prime(n / i)) list.push_back(n / i);
            }
        }
    }

    return list;
}

// method 3

vector<int> findPrimeFactorsMethod3(int n) {
    vector<int> list;

    // Worst-case TC is O(root(N) * logN)
    // logN is written when we do divisions
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (prime(i)) list.push_back(i);
            while (n % i == 0) {
                n = n / i;
            }
            // Here, unlike the 2nd method, we need not check n/i != i
            // as anyways we are doing it by n = n/i
        }
    }
    if (n != 1) list.push_back(n);
    // Last line is important as there are 2 cases.
    // In most cases, it is like we had checked from i = 2 step by step and divided the number till we can.
    // Ex: 42 = 2, root(42). 3, root(21). 4, root(7). We have to check from 2 to root(7) for number 7.
    // But already 2, 3 are over. So, the only option left was 7.

    // But only in the case of powers of 2, n is 1. Here we can't add 1 as it is not prime.

    return list;
}

// Time Complexity: O(sqrt(N))
// Space Complexity: O(1) (excluding the space required for the output vector)


