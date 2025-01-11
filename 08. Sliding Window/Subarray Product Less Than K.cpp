// count question - non shrinkable can't be used here
// If the subarray product needs to be k, then we can use atMost(k+1) - atMost(k)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        if (k == 0) return 0;
        long i = 0, j = 0, n = A.size(), prod = 1, ans = 0;
        for (j = 0; j < n; j++) {       // it is fine to write again
            prod = prod * A[j];
            while (i <= j && prod >= k) {       // here i<=j, the element can be greater than k, so i=j+1 and ans += 0;
                prod /= A[i];   i++;
            }    
            ans += j - i + 1;       // we are adding all the possible answers having ending at j. i.e, (i,j) (i+1,j) ...(j,j)
        }
        return ans;
    }
};