// Here, the i<=j is important
// as goal=0 is also possible, so here i=j is possible

// We will be traversing using the j pointer and we will shrink the i pointer to maintain the atMost, there will be no such thing for the atMost

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int i = 0, j = 0, n = nums.size(), ans = 0, sum = 0;
        for (j=0; j<n; j++) {
            if(nums[j]==1) sum++;
            while (i<=j && sum > goal) {
                if(nums[i]==1) sum--;
                i++;
            }
            ans = ans + (j-i+1);      // already 'i' is advanced by 1
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};