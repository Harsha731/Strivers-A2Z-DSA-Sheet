class Solution {
  public:
int totalFruits(int N, vector<int> &fruits) {
    unordered_map<int, int> mpp;
    int left = 0, right = 0;
    int len = 0;

    while (right < N) {
        mpp[fruits[right]]++;
        
        while (mpp.size() > 2) {
            mpp[fruits[left]]--;
            if (mpp[fruits[left]] == 0) {
                mpp.erase(fruits[left]);
            }
            left++;
        }

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
};