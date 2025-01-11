// Usage of the 'min' is the key here

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0, ans = 0, n = answerKey.size();
        int t = 0, f = 0;
        for(j=0; j<n; j++) {
            if (answerKey[j] == 'T') t++;
            else f++;
            while ( min(t,f) > k) {
                if (answerKey[i] == 'T') t--;
                else f--;      
                i++;          
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

// ____________________________________________

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0, ans = 0, n = answerKey.size();
        int t = 0, f = 0;
        for(j=0; j<n; j++) {
            if (answerKey[j] == 'T') t++;
            else f++;
            if ( min(t,f) > k) {
                if (answerKey[i] == 'T') t--;
                else f--;      
                i++;          
            }
        }
        return j-i;
    }
};