/*
QUESTION:
Given an integer n, return the number of prime numbers that are strictly less than n.

Example:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, which are 2, 3, 5, and 7.

APPROACH:
To count the number of prime numbers less than a given number n, we can use the Sieve of Eratosthenes algorithm.
1. Create a boolean vector `primes` of size n+1 and initialize all elements to true. This vector will be used to mark numbers as prime or not.
2. Initialize a variable `cnt` to count the number of primes.
3. Iterate from 2 to n-1:
   - If primes[i] is true (i.e., i is a prime number), increment `cnt`.
   - Mark all multiples of i as false in the `primes` vector, as they are not prime.
4. Return `cnt`, which will be the count of prime numbers less than n.

CODE:*/
int countPrimes(int n) {
    vector<bool> primes(n + 1, true);
    int cnt = 0;
    for (long long i = 2; i < n; i++) {
        if (primes[i]) {
            cnt++;
            for (long long j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return cnt;
}

	2*i  -->  i*i
for good TC

i max is root(N)
as j=i*i will be out of bound

we can also written as i*i<=N instead i<root(N)

TC is N + N*log(log(N)) + N
prime harmonic series - derivation is hard - just remember it
SC is N 
______________________________

// No need

prime[n+1];
for(i=2;i<=n;i++) prime[i]=1;
for(i=2;i<=n;i++){
    if(prime[i]==1){
        for(j=2*i;j<=N;j+=i){
            prime[j]=0;
        }
    }
}

// Important

prime[n+1];
for(i=2;i<=n;i++) prime[i]=1;
for(i=2;i<=root(n);i++){        //root(n)
    if(prime[i]==1){
        for(j=i*i;j<=N;j+=i){    //i*i
            prime[j]=0;
        }
    }
}



// Time Complexity: O(n log log n)
// Space Complexity: O(n)


