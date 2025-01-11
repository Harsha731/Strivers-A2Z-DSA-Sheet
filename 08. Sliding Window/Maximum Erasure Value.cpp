class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0, j=0, ans = 0, n = nums.size(), sum = 0;
        unordered_map <int,int> ump;
        for (j=0; j<n; j++) {
            ump[nums[j]]++;
            sum = sum + nums[j];
            while (ump[nums[j]] > 1) {
                sum = sum - nums[i];
                ump[nums[i]]--;
                if(ump[nums[i]] == 0) ump.erase(nums[i]);
                i++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

// We can't do non shrinkable here as it gives the wrong sum value