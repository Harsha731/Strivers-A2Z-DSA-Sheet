// We are adding ans+= (n-r) as many times as the 'l' can be shifted. 
// i.e, for every l possible, we are able to get n-j extra substrings 
// (l,r) (l,r+1) (l,r+2) ... (l,n-1)

// But if we do ans+= (l+1), it means as l is shifting, then 
// (0,r) (1,r) (2,r) ... (l,r) 
// and we shift l next, again the same comes
// (0,r) (1,r) (2,r) ... (l+1,r) if it still valid
// Thus repetetions are present

// Don't try to take based on l, instead take only based on r

// This is count questions - type 4

class Solution {
public:
    unordered_map <int, int> ump;
    bool valid() {
        if(ump[0] && ump[1] && ump[2]) return true;
        return false;
    }

    int numberOfSubstrings(string s) {
        int i = 0, j = 0, n = s.length(), ans = 0;
        for(j=0; j<n; j++) {
            ump[s[j]-'a']++;
            while(valid()) { 
                ans = ans + (n-j);
                ump[s[i]-'a']--;  
                i++;
            }
        }
        return ans;
    }
};