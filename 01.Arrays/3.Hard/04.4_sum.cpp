/*
QUESTION:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

APPROACH:
To find the unique quadruplets that sum up to the target, we can use a similar approach as the threeSum problem. We will fix two elements (nums[a] and nums[b]) and use two pointers to find the remaining two elements (nums[c] and nums[d]) that sum up to the target.

1. Sort the input array nums in ascending order.
2. Iterate through the array with two pointers: a and b.
3. For each pair of elements nums[a] and nums[b], use two pointers c and d to find the remaining two elements that sum up to the target.
   - Initialize c as b + 1 and d as the last index of the array.
   - Calculate the target sum as trgt = target - (nums[a] + nums[b]).
   - While c < d, compare the sum of nums[c] and nums[d] with the target sum.
     - If the sum is equal to the target sum, we found a quadruplet. Add it to the answer and move the pointers c and d.
       - Important: Skip any duplicate elements while moving c and d.
     - If the sum is greater than the target sum, decrement d.
     - If the sum is less than the target sum, increment c.
4. Skip any duplicate elements for pointers a and b to avoid duplicate quadruplets.
5. Return the answer array containing unique quadruplets.


CODE:
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long t = target;

    for (int a = 0; a < n - 3; ++a) {
        if (a > 0 && nums[a] == nums[a - 1]) continue;

        for (int b = a + 1; b < n - 2; ++b) {
            if (b > a + 1 && nums[b] == nums[b - 1]) continue;

            int c = b + 1, d = n - 1;
            long long sumAB = (long long)nums[a] + nums[b];

            while (c < d) {
                long long sumCD = nums[c] + nums[d];
                if (sumAB + sumCD == t) {
                    res.push_back({nums[a], nums[b], nums[c++], nums[d--]});

                    while (c < d && nums[c] == nums[c - 1]) ++c;
                    while (c < d && nums[d] == nums[d + 1]) --d;
                } else if (sumAB + sumCD < t) {
                    ++c;
                } else {
                    --d;
                }
            }
        }
    }

    return res;
}

/*
TIME COMPLEXITY: O(n^3), where n is the size of the input array nums.
SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space.
*/
