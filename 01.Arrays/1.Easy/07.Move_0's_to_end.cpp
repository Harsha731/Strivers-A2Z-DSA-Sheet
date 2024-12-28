/*
QUESTION:-
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

/*
APPROACH:-
-> 1. Initialize Variables :
Find the first zero's position and store it in j.
If no zero is found, return immediately.

2. Iterate Through Vector
Traverse the vector starting from the position after j.

3. Check Non-Zero Elements
If a non-zero element is found, swap it with the element at j.

4. Update Pointer
Increment j after each swap to point to the next zero position.
*/

// CODE:-
// function to find the next non-zero element
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = -1;

    // Place the pointer j:
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    // No non-zero elements:
    if (j == -1) return;

    // Move the pointers i and j and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}


// TIME COMPLEXITY = O(N) (as we moving j throught the array only once)
// SPACE COMPLEXITY = O(0)
