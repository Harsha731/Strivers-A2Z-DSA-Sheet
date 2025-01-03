/*
Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and 
then a mod operation with 100000 is done to get the new start. Your task is to find the minimum steps in which the end 
can be achieved starting from the start. If it is not possible to reach the end, then return -1.

Input:
arr[] = {3, 4, 65}
start = 7
end = 66175
Output:
4
Explanation: 
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 6 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
Therefore, in minimum 4 multiplications we reach the end number which is treated as a destination node of a graph here.

Time Complexity : O(100000 * N) 
Space Complexity :  O(100000 * N) 
  
we use         vector<int> dist(100000, 1e9);
we use queue here as we go in BFS manner here	
We check if ( steps + 1 < dist[num] )
*/

class Solution {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        queue<pair<int, int>> q;
        q.push({start, 0});

        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr) {
                int num = (it * node) % mod;

                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;

                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
