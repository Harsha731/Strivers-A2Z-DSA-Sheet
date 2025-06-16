/*QUESTION:

Given an integer array nums, find a subarray that has the largest product, and return the product.

Example:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

APPROACH:

To find the subarray with the largest product, we iterate through the array while keeping track of the current product. We maintain two variables: `ans` to store the maximum product found so far and `prdct` to store the current product. Since negative numbers can change the sign and potentially result in a larger product, we run the loop twice, once from left to right and once from right to left.

All possible cases :-
1) Contains zeros (e.g. [2, 0, -3, 4])
2) Negative numbers flipping signs (e.g. [-2, 3, -4])
3) Single element arrays (e.g. [-3])
4) All negative numbers (e.g. [-2, -3, -7])
5) Multiple zeros (e.g. [0, -2, 0, -3, 0])

CODE:*/

class Solution {
public:
    int maxProduct(vector<int>& A) {
        int maxProd = 1, minProd = 1;
        int ans = INT_MIN;
        for (int n : A) {
            int a = n * maxProd, b = n * minProd;
            maxProd = max({n, a, b});
            minProd = min({n, a, b});
            ans = max(ans, maxProd);
        }
        return ans;
    }
};

// ________________________________________

// 0 .....   0 1...5.... 9...0   ......
// left to right makes portion from 1 to 5 covered and right to left makes portion from 9 to 5 covered

int maxProduct(vector<int>& nums) {
    int ans = INT_MIN;
    int prdct = 1;

    // Iterate from left to right
    for (int i = 0; i < nums.size(); i++) {
        prdct = prdct * nums[i];
        ans = max(ans, prdct);
        if (prdct == 0)
            prdct = 1;
    }

    prdct = 1;

    // Iterate from right to left
    for (int i = nums.size() - 1; i >= 0; i--) {
        prdct = prdct * nums[i];
        ans = max(ans, prdct);
        if (prdct == 0)
            prdct = 1;
    }

    return ans;
}

/*
TIME COMPLEXITY: O(N), where N is the size of the input array.
SPACE COMPLEXITY: O(1).
*/
