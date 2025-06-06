/*
Question:
Given two integer arrays A and B of size N each. A sum combination is made by adding one element from array A and another element from array B. Return the maximum K valid distinct sum combinations from all the possible sum combinations. Output array must be sorted in non-increasing order.

Example:
Input:
N = 2
K = 2
A[] = {3, 2}
B[] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A: 3) + (B: 4)
6 -> (A: 2) + (B: 4)
*/

/*
Approach:
1. Sort arrays A and B in non-increasing order.
2. Initialize a min-heap (priority_queue) to store the sum combinations.
3. Iterate over each element in array A.
4. For each element in A, iterate over each element in array B.
5. Calculate the sum of the current pair (A[i] + B[j]).
6. If the heap size is less than K, push the sum into the heap.
7. If the heap size is already K and the current sum is greater than the smallest element in the heap, pop the smallest element and push the current sum into the heap.
8. After iterating over all elements, the heap will contain the K maximum valid sum combinations in non-increasing order.
9. Store the elements of the heap in a vector and return it as the result.

COMPLEXITY ANALYSIS:-
TIME COMPLEXITY - 
Sorting the arrays A and B takes O(N log N) time.
Building the max heap takes O(N) time.
Extracting the maximum sum K times takes O(K log N) time.
Overall, the time complexity of the solution is O(N log N + K log N).
CODE:-
*/

// We won't insert all the NM into the queue
// TC : O(nlogn) for sorting + O(nlogn) for pushing n elements in PQ + O(nlogn) push and pop for the K elements
// We push the (i,j) = (0,n-1) (1,n-1) (2,n-1) ... (m-1,n-1)
// We pop the top (p,q) and we push the (p, q-1) as it can be next possible answer

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < N; ++i)
        pq.push({A[i] + B[N - 1], {i, N - 1}});

    vector<int> ans;
    while (K-- && !pq.empty()) {
        auto [sum, pos] = pq.top();
        pq.pop();
        ans.push_back(sum);

        int x = pos.first, y = pos.second;
        if (y > 0)
            pq.push({A[x] + B[y - 1], {x, y - 1}});
    }

    return ans;
}
