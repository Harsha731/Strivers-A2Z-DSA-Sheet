// seperate function is not needed
// i<=j is not needed, because k can't be 0, so atleast 1 element has to be there

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt = 0, n = nums.size();
        unordered_map<int, int> mp;

        for (j = 0; j < n; ++j) {
            int cur = nums[j];
            mp[cur]++;
            while (i < j && mp[cur] > k) {
                mp[nums[i]]--;
                i++;
            }
            cnt = max(cnt, j - i + 1); // j - i + 1 to include the current element in the subarray
        }
        return cnt;
    }
};
