/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return 
an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/*
APPROACH :
We sort based on startTime and We go from L to R
Here, we get 2 cases
If it is overlapping, we update the v.back().endTime to newOne
Else, simply insert the new interval

Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop 
that runs for N times. So, the time complexity will be O(N).

Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, 
we are not using any extra space.

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i<intervals.size(); i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else 
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
};
