// We add the cnts from string A and we subtract from B, if the 2 strings 2 are same by permuatation
// Then, the cnts[] will be 0 for aall indices, then match will remain true
// Atleast, one true is enough to return true

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int M = s1.size(), N = s2.size();
        if (M > N) return false;
        int goal[26] = {0}, cnt[26] = {0};
        for (char c : s1) goal[c - 'a']++;

        int i = 0;
        for (int j = 0; j < N; ++j) {
            cnt[s2[j] - 'a']++; 

            // Shrink the window if needed
            while (cnt[s2[j] - 'a'] > goal[s2[j] - 'a']) 
                cnt[s2[i++] - 'a']--;

            // Check if the current window has the same size as s1
            if (j - i + 1 == M) return true;
        }

        return false;
    }
};
// ___________________________

class Solution {
public:
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;

        int cnt[26] = {0};

        // Initialize frequency count for string `a`
        for (char c : a) cnt[c - 'a']++;

        // Sliding window over string `b`
        for (int i = 0, j = 0; j < b.size(); ++j) {
            cnt[b[j] - 'a']--; // Decrement the count for the current character in `b`

            // If count goes negative, shrink the window from the left
            if (cnt[b[j] - 'a'] < 0) {
                while (b[i] != b[j]) cnt[b[i++] - 'a']++; // Increment count for skipped characters
                cnt[b[i++] - 'a']++; // Increment count for `b[i]` to remove it from the window
            }

            // Check if the current window size matches the length of `a`
            if (j - i + 1 == a.size()) return true;
        }

        return false;
    }
};
    