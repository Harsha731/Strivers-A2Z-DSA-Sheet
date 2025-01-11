// Time: O(NlogN)
// Space: O(1)

// We sort and remove the duplicat elements at start
// We move the j from start 0 to n-1
// We keep i=0 at start and if any (i, j) is not able to satisfy in [1, n] we shift the i
// Here, we can get the possible window size for that particular j
// Then, N-ans is the operations to be done to get continous array

class Solution {
public:
    int minOperations(vector<int>& A) {
        
        int N = A.size(), i = 0, j, ans = 0;
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end()); // Remove duplicates

        for (j=0; j < A.size(); ++j) {
            while (A[i] + N <= A[j]) ++i; // Keep A[i] in range [A[j] - N + 1, A[j]]
            ans = max(ans, j - i + 1);
        }

        return N - ans; // Minimum operations needed
    }
};

// _________________________________

// We can simply change the while to if to get non shrinkable approach
// But we generally don't use ans in the 2nd approach

class Solution {
public:
    int minOperations(vector<int>& A) {
        int N = A.size(), i = 0, j;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements

        for (j=0; j < A.size(); ++j) {
            if (A[i] + N <= A[j]) ++i;
        }
        return N - (j - i);   // as j is already at n. i,e j is j+1
    }
};