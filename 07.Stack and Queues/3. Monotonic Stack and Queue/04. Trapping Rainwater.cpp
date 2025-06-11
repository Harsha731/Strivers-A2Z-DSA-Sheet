/*QUESTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

APPROACH:
To calculate the trapped water, we can use the two-pointer approach. We initialize two pointers, one at the beginning of the array (`left`) and another at the end of the array (`right`). We also maintain two variables, `leftMax` and `rightMax`, to keep track of the maximum bar height encountered from the left and right side, respectively.

1. Initialize `left` to 0 and `right` to the last index of the array.
2. Initialize `leftMax` and `rightMax` to the minimum integer value (`INT_MIN`).
3. Initialize `ans` (trapped water) to 0.
4. Iterate while `left` is less than or equal to `right`:
    a. If `height[left]` is less than `height[right]`:
        - Update `leftMax` if `height[left]` is greater than the current `leftMax`.
        - Calculate the amount of water trapped at the current `left` index by subtracting `height[left]` from `leftMax` and add it to `ans`.
        - Increment `left` by 1.
    b. Else:
        - Update `rightMax` if `height[right]` is greater than the current `rightMax`.
        - Calculate the amount of water trapped at the current `right` index by subtracting `height[right]` from `rightMax` and add it to `ans`.
        - Decrement `right` by 1.
5. Return the final value of `ans`.

-> We need to focus on the height[left] if it is height[left] < height[right] , now if the leftMax < hegiht[left]. So, height[left] can store leftMax - height[left]
-> If height[left] < height[right] and height[left] < leftMax, then leftMax < height[right] for sure
    Because, we did left++ only if the pastHeight < 
-> left will be pointing 

CODE:*/

// TC : O(N^2) and SC : O(1) 
// For each element, find its max on left, max on right. Take the min of the both. 
// ans += min(leftMax, rightMax) - elementValue

int trap(vector<int>& arr) {
    int n = arr.size();
    int waterTrapped = 0;

    // Iterate through each bar
    for (int i = 0; i < n; i++) {
        int leftMax = 0, rightMax = 0;

        // Find the maximum height to the left of the current bar
        for (int j = i; j >= 0; j--) {
            leftMax = max(leftMax, arr[j]);
        }

        // Find the maximum height to the right of the current bar
        for (int j = i; j < n; j++) {
            rightMax = max(rightMax, arr[j]);
        }

        // Calculate the water trapped at the current bar
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }

    return waterTrapped;
}
______________________________________

//  TC : O(3N) and SC : O(2N)
// Do one traversal to find the max on left side, same for max on right side
// Then one more traversal for ans += min(leftMax, rightMax) - elementValue
	
int trap(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0; // Handle edge case

    // Arrays to store the maximum heights
    vector<int> prefix(n), suffix(n);

    // Calculate the prefix maximum heights
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }

    // Calculate the suffix maximum heights
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }

    // Calculate the total water trapped
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }

    return waterTrapped;
}
______________________________________

// 2 pointer approach - O(N) TC and O(1) SC

/*  Content is there at the top too
left = 0, right = n-1, leftMax = rightMax = INT_MIN, ans = 0
if ( height[left] < height[right] )
	if ( height [left] <= leftMax ) here storage happens. i.e, ans += leftMax - height[left];
	else here updation of leftMax happens by decreasing its value
Do left++
Same with right pointer too

If we are moving left++, it means the right is at peak till now, height[right] = rightMax
So, the addition of water depends on leftMax as leftMax < rightMax, else left++ won't occur at all

If leftMax got updated means, there is nothing more than that height on its left. So, it can't store rain water
If left++ is getting updated it means, left_cur < right_cur and leftMax is the max height from i=0 to current

*/

int trap(vector<int>& height) {
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int left = 0, right = height.size()-1;
    int ans = 0;

    while(left <= right) {
        if(height[left] < height[right]) {
            if(height[left] > leftMax)
                leftMax = height[left];
            else
                ans += leftMax - height[left];
            left++;
        } else {
            if(height[right] > rightMax)
                rightMax = height[right];
            else
                ans += rightMax - height[right];
            right--;
        }
    }

    return ans;
}
/*
COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(N), where N is the number of elements in the `height` array. We iterate through the array once.
- The space complexity is O(1) as we only use a constant amount of extra space to store variables.
*/


