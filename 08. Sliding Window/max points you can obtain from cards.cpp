We had did in reverse, we can also do in direct way as follows,
first calculate the k indexes sum, then subtract each and add on right side

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totalSum = 0;
        for (int point : cardPoints) {
            totalSum += point;
        }
        if (k == n) return totalSum;

        int left=0, right=0;
    
        int minSum = 0, sum = 0;
        while(right<n){         //imp
            if(right <= n-k-1) {        //imp
                sum+=cardPoints[right];
                right++;
                minSum = sum;
            }
            else {
                sum+= cardPoints[right]-cardPoints[left];
                minSum = min(minSum, sum);
                right++;
                left++;
            }
        }
        return totalSum - minSum;
    }
};