// 2 pointers

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& A) {
        int sum = 0, N = A.size(), i = 0, ans = INT_MAX;
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while (sum >= target) {
                ans = min(ans, j - i + 1); // +1 because j is inclusive in the subarray
                sum -= A[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// _____________________________________________________

// Binary search
// In the question, it is given to think a NlogN solution, so here is the approach

class Solution {
public:
    bool valid(int len, int target, vector<int>& A) {
        int sum = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (i - len >= 0) sum -= A[i - len];
            if (sum >= target) return true;
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& A) {
        int N = A.size(), L = 1, R = N;
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M, target, A)) R = M - 1;
            else L = M + 1;
        }
        return L > N ? 0 : L;
    }
};
