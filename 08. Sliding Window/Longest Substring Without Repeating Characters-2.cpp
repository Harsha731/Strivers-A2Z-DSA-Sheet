class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, n = s.size(), cnt = 0, ans = 0;
        int ump[128] = {};

        for (int j = 0; j < n; j++) {
            if (++ump[s[j]] > 1) cnt++;

            while (cnt > 0) {
                if (--ump[s[i]] == 1) cnt--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

// Non shrinkable is possible here