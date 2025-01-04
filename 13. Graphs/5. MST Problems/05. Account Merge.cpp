/*
QUESTION:-
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email 
to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could 
have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, 
and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
*/

/*
what happens in the sort ?

1) We keep on inserting the mails in umap(string, i), if there is any duplicate, we connect the i's

2) Now, arrange in the actual order in adjacent list, here some i's may become empty which are not empty earlier

3) Now, insert the user name of the account in the temp vector and push all the emails in adj list to temp vector
Then, push the temp vector to ans 2D vector
Here, we have to sort as the emails won't be in sorted order

We are using 'ump' for mapping the email to its index
Then, we are using '2D vector' for merging and inserting all the emails under same user. Here, some entries are empty too
Then, '2D ans' vector is used for removing those empty 1D vectors and also we add username at start and also we sort them before returning

Pass by reference to save TC and SC too much

Complexity Analysis:
- Let n be the number of accounts and m be the average number of emails per account.
- The time complexity of this approach is O(n*m*α(n)), where α(n) is the inverse Ackermann function, which grows very slowly and is nearly constant.
- The space complexity is O(n*m) to store the emails and their corresponding account indices in the unordered map, and O(n*m) to store the merged accounts in the final result.

*/
__________________________

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accs) {
        int n = accs.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailMap;

        // Build the disjoint set with email mapping
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accs[i].size(); ++j) {
                const string& email = accs[i][j];
                if (emailMap.find(email) == emailMap.end()) {
                    emailMap[email] = i;  // Map email to account index
                } else {
                    ds.unionBySize(i, emailMap[email]);
                }
            }
        }

        // Group emails by their representative account
        vector<vector<string>> emailGroups(n);
        for (const auto& [email, idx] : emailMap) {
            int root = ds.findUPar(idx);
            emailGroups[root].push_back(email);
        }

        // Construct the result
        vector<vector<string>> res;
        for (int i = 0; i < n; ++i) {
            if (emailGroups[i].empty()) continue;

            // Sort the emails
            sort(emailGroups[i].begin(), emailGroups[i].end());

            // Prepare the merged account
            vector<string> temp;
            temp.push_back(accs[i][0]);  // Add the name
            temp.insert(temp.end(), emailGroups[i].begin(), emailGroups[i].end());

            res.push_back(temp);
        }

        return res;
    }
};
