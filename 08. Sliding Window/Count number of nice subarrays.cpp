	
use the same method as 	
Binary subarray with sum

first traverse and change the array to 0, 1 by checking odd or even


class Solution {
    int atMost(vector<int> &A, int k) {
        int i = 0, j = 0, n = A.size(), ans = 0, cnt = 0;
        for (j = 0; j < n; ++j) {
            if (A[j] % 2) cnt++;
            while (cnt > k) {
                if (A[i] % 2) cnt--;
                i++;
            }
            ans = ans + ( j - i + 1 );
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }
};