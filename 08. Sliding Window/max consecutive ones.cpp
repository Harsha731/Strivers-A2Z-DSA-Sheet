This is O(N^2) TC and O(1) SC

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxl = 0;
        for(int i=0;i<n;i++){
            int zeros = 0;
            for(int j=i;j<n;j++){
                if(nums[j]==0) zeros++;
                if(zeros<=k){
                    int len = j-i+1;
                    maxl = max(maxl, len);
                }
                else break;
            }
        }
        return maxl;
    }
};
____________________________

TC is O(2N) and SC is O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zeros = 0;
        int maxl = 0;
        while(r<n){
            if(nums[r]==0) zeros++;
            while(zeros > k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r-l+1;
                maxl = max(maxl, len);
            }
            r++;
        }
        return maxl;
    }
};
___________________________

TC is O(n)
The while loop is changed to single if statement

We don't have a problem if the max 0's had not reached
Also, no prob if reached but the current element is 1

For suppose we had shifted the max 0's and the current element is 0. There is a problem
If the nums[l] == 0, we are safe
else, if nums[l] == 1. Don't decrease the max length, and increase it only when the zero's had been reasonable

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zeros = 0;
        int maxl = 0;
        while(r<n){
            if(nums[r]==0) zeros++;
            if(zeros > k){		// it can be more than k+1 too in this 3rd method
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r-l+1;
                maxl = max(maxl, len);
            }
            r++;
        }
        return maxl;
    }
};