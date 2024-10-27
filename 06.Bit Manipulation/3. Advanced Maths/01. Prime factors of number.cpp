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
vector<int> AllPrimeFactors(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ans.push_back(n);
    return ans;
}

list = [];

method 1)

// TC is O(N*root(N))
// SC depends on input, as we are not using any space for space but only for output list
for (int i=2;i<=n;i++){
    if(n%i == 0){
        if(prime(i)) list.add(i);
    }

    
}

method 2)

// TC is O(root(N)*root(N))
for (int i=2; i*i<=n; i++){
    if(n%i == 0){
        if(prime(i)) list.add(i);
    	if(n/i != i){ 			// not a perfect square like 6*6 = 36
        	if(prime(n/i)) list.add(n/i);
	}
    }    
}

// leave this

// TC is O(N) in worst case, but can reduce very much in average cases
// same like normal division
for (int i=2;i<=n;i++){
    if(n%i == 0){
        if(prime(i)) list.add(i);
        while(n%i==0) {
            n = n/i;
        }
    }
}

method 3)

// worst case TC is O(root(N)*logN)
//logN is written when we do divisions
for (int i=2; i*i<=n; i++){
    if(n%i == 0){
        if(prime(i)) list.add(i);
        while(n%i==0) {
            n = n/i;
        }
// Here, unline the 2nd methos, we need not do check n/i != i 
// as anyways we are doing it by n = n/i
    }
}
if(n!=1) list.add(n);
// Last line is important as there are 2 cases. 
// In most of the cases, it is like we had checked from i=2 step by step and divided the number till we can
// ex is 42 = 2,root(42). 3,root(21). 4,root(7). We have to check from 2 to root(7) for number 7. 
// But already 2,3 over. So, only option left was 7.

// But only in the case of power of 2, the n is 1, here we can't add 1 as it is not prime.




// Time Complexity: O(sqrt(N))
// Space Complexity: O(1) (excluding the space required for the output vector)


