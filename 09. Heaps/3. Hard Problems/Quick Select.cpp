// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)

class Solution {
    int dist(const vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }

    int partition(vector<vector<int>>& A, int L, int R) {
        int i = L, pivotIndex = L + rand() % (R - L + 1), pivot = dist(A[pivotIndex]);
        swap(A[pivotIndex], A[R]); // swap the pivot to the end of this subarray

        for (int j = L; j < R; ++j) { // traverse from L to R - 1. Note that we don't visit A[R] which is the pivot
            if (dist(A[j]) < pivot) {
                swap(A[i++], A[j]);
            }
        }
        swap(A[i], A[R]); // Place pivot in its correct position
        return i; // Return the index of the pivot
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int k) {
        int L = 0, R = A.size() - 1;

        while (true) {
            int M = partition(A, L, R);
            if (M + 1 == k) break;
            if (M + 1 < k) L = M + 1;
            else R = M - 1;
        }

        return vector<vector<int>>(begin(A), begin(A) + k);
    }
};
