// Solution 1. Find Maximum Sliding Window

// Time: O(N)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int N = A.size(), i = 0, sum = 0, target = accumulate(A.begin(), A.end(), 0) - x, maxLen = -1;
        if (target < 0) return -1;
        
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while (sum > target) sum -= A[i++];
            if (sum == target) maxLen = max(maxLen, j - i + 1);
        }
        
        return maxLen == -1 ? -1 : N - maxLen;
    }
};

// Solution 2. Not needed as it is new approach 