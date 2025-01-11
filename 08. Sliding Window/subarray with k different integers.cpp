class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            map<int,int> mpp;
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                if(mpp.size()==k) cnt++;
                else if(mpp.size()>k) break;
            }
        }
        return cnt;
    }
};
_______________________________________

[ 2 1 1 (1) 3 4 3 2 ]
We take the circled 1, then we are considering 4 new sub arrays
Only if map size is less than k, this is helpful

But the map contain for much time, its size is less than k

But, later it will have a constant K, if it becomes k+1, shrink down till it become k

Even at that time, count += count + (r-l+1)

class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l = 0, r = 0;
        long long int cnt = 0;
        unordered_map<int, int> mpp;

        while (r < nums.size()){
            mpp[nums[r]]++;

            while(mpp.size()>k){
                mpp[nums[l]]--;
                if (mpp[nums[l]]==0) {
                    mpp.erase(nums[l]);
                    
                }
                l++;
            }
                cnt= cnt + (r-l+1);
                r++;
            
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};