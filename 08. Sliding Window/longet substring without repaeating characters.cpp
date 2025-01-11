TC and SC are very less
But I did on my own

We can optimize this, as j is not needed, only k is enough
As if there exists something with before chars, then it will be already calculated in the earlier iterations

so, 
                if (k + 1 < n && mp.count(s[k + 1]) == 0) {
                    k++;
                    mp[s[k]] = 1;  // Add the character to the map
                }
                else break;  // If neither j nor k moved, break the loop

TC is O(N^2) and SC is O(N)

Also, us unordered map when the order is not important
_____________________________________________________

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int j = i, k = i;
            map<char, int> mp;  // Use map<char, int> instead of map<int, int>
            mp[s[i]] = 1;  // Add the current character to the map
            while (true) {
                bool moved = false;
                if (j - 1 >= 0 && mp.count(s[j - 1]) == 0) {
                    j--;
                    mp[s[j]] = 1;  // Add the character to the map
                    moved = true;
                }
                if (k + 1 < n && mp.count(s[k + 1]) == 0) {
                    k++;
                    mp[s[k]] = 1;  // Add the character to the map
                    moved = true;
                }
                if (!moved) break;  // If neither j nor k moved, break the loop
            }
            maxi = max(maxi, k - j + 1);
        }
        return maxi;
    }
};
____________________________________

optimized approach with TC O(2*N) in worst case
SC is O(N)

ab(c)defgh(c)
Here l is at a and r is at c, here l is traversed till d, all elements in the path get erased from the set

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}
________________________

optimized 2)

Here,   left = max(mpp[s[right]] + 1, left);
is important as the element may exists but it can be left to the left pointer, then keep left at same index. Else if it is on the right, update it to index+1
Here, left will updated when right updates, unlike in the past, where left updates independently of right
TC is O(N) and not O(2N) and SC is O(N)

class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
