/*
Question:
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.

Approach:
1. Create a frequency map to count the occurrences of each character in the string.
2. Use a priority queue to sort the characters based on their frequencies in decreasing order.
3. Iterate through the priority queue and append the characters to a new string according to their frequencies.

Code:
*/

string frequencySort(string s) {
    unordered_map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto it : mp) {
        pq.push({ it.second, it.first });
    }

    string ans = "";
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        ans.append(curr.first, curr.second);
    }

    return ans;
}

/*
Time Complexity: O(n log n), where n is the length of the string. Building the frequency map takes O(n) time, and the priority queue operations take O(n log n) time.
Space Complexity: O(n), where n is the length of the string. The space is used to store the frequency map and the priority queue.
*/

// Bucket Sort
// TC : O(N) and SC : O(N)
// SC compromised for TC

// We create a vector of n+1 size and push all the characters having that particular frequency

class Solution {
public:
    string frequencySort(const string& s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        for (char c : s)  cnt[c] += 1;
        
        vector<vector<char>> bucket(n+1);
        for (auto [c, f] : cnt)
            bucket[f].push_back(c);
        
        string ans;
        for (int freq = n; freq >= 1; --freq)
            for (char c : bucket[freq]) 
                ans.append(freq, c);
        return ans;
    }
};
