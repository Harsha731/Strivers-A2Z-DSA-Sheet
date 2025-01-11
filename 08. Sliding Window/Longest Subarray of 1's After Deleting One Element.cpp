// The main thing is j-i instead of j-i+1 as we 'should' delete a element from nums
// j-i-1 for 2nd approach

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, ans = 0, n = nums.size();
        int z = 0;
        for (j=0; j<n; j++) {
            if(nums[j] == 0) z++;
            while(z > 1) {
                if(nums[i++] == 0) z--;
            }
            ans = max(ans, j-i); 
        }
        return ans;
    }
};


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, ans = 0, n = nums.size();
        int z = 0;
        for (j=0; j<n; j++) {
            if(nums[j] == 0) z++;
            if (z > 1) {
                if(nums[i++] == 0) z--;
            }
        }
        return j-i-1;
    }
};