class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n==0 || n==1) return n;
        int maxl = 0;
        for(int i=0;i<n;i++){
            vector<int> hash(26, 0);
            int maxf = 0;
            int changes = 0;
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxf = max(maxf, hash[s[j]-'A']);
                changes = (j-i+1) - maxf;
                if(changes<=k) maxl = max(maxl, j-i+1);
            }
        }
        return maxl;
    }
};
________________________________

We can trim out the O(26) in TC as hash need not be decreased
Also, we can trim out the remaining O(N) as while loop -> if statement
We need not decrease the length, as it is not needed

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> m;
        int maxlen = 0;
        int l = 0, r = 0;
        int n = s.length();
        int maxfreq = 0;
        while (r < n) {
            m[s[r] - 'a']++;
            maxfreq = max(maxfreq, m[s[r] - 'a']);
            int len = r - l + 1;
            int change = len - maxfreq;

            if (change > k) {
                m[s[l] - 'a']--;
                l++;
            }
            else {
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};