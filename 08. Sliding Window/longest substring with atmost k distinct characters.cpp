https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string s, int k) {

    int n = s.length();
    int maxLen = -1;
    map <char, int> mpp;

    int left = 0, right = 0;
    while(right<n){
        mpp[s[right]]++;
        
        while(mpp.size()>k){
            mpp[s[left]]--;
            if(mpp[s[left]]==0) mpp.erase(s[left]);
            left++;
        }
        
        if(mpp.size()==k) {
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }

    return maxLen;
}