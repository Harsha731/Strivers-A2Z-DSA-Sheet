// Here, max element means max of the array, not the sub array. That question is different

class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        long long N = A.size(), ans = 0, cnt = 0;
        int mx = *max_element(begin(A), end(A)), i = 0, j;

        for (j = 0; j < N; ++j) {
            cnt = cnt + (A[j] == mx);
            while (cnt >= k)
                cnt = cnt - (A[i++] == mx);
            ans += i;       // At least we have i total with the current j
        }   
        return ans;
    }
};
