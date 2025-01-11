// We had did in reverse, we can also do in direct way as follows,
// first calculate the k indexes sum, then subtract each and add on right side

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


// ______________________________

// latest approach of finding the minimum window sum of n-k elements and the reverse is the max

class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int total = 0;
        int n = cards.size();

        for (int card : cards) {
            total += card;
        }

        // Calculate the initial sum of the first (n - k) elements
        int minWindow = 0;
        for (int i = 0; i < n - k; ++i) {
            minWindow += cards[i];
        }

        // Use a sliding window to find the minimum sum of any subarray of size (n - k)
        int currentWindow = minWindow;
        for (int i = n - k; i < n; ++i) {
            currentWindow += cards[i] - cards[i - (n - k)];
            minWindow = min(minWindow, currentWindow);
        }

        return total - minWindow;
    }
};
