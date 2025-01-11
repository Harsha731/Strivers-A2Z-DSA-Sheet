#include <bits/stdc++.h>>

int kDistinctChars(int k, string &s)
{
    // Write your code here
    int i = 0, n = s.size(), cnt = 0, ans = 0;
    unordered_map <int,int> ump;

    for (int j = 0; j < n; j++) {
        ump[s[j]-'a']++;
        if (ump[s[j]-'a'] == 1) cnt++;

        while (cnt > k) {
            ump[s[i]-'a']--;
            if (ump[s[i]-'a'] == 0) cnt--;
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}



#include <bits/stdc++.h>>

int kDistinctChars(int k, string &s)
{
    // Write your code here
    int i = 0, j = 0, n = s.size(), cnt = 0, ans = 0;
    unordered_map <int,int> ump;

    for (j = 0; j < n; j++) {
        ump[s[j]-'a']++;
        if (ump[s[j]-'a'] == 1) cnt++;

        if (cnt > k) {
            ump[s[i]-'a']--;
            if (ump[s[i]-'a'] == 0) cnt--;
            i++;
        }
    }
    return j-i;
}