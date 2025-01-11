We can do using 2 pointer as well as hashing
hashing is already done, count sub

class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size(); // size of the array.
        
        int left = 0, right = 0;
        int sum = 0, count = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum > goal && left<=right) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solve(nums, goal) - solve(nums, goal-1);
    }
};