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

// In this question, if 2 differnt users have same email, then we are assuming they are same. So, they should have 
// same name, but if they have differnt names, then we are are returning it with the name appeared first

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
____________________________________________________________

// DFS

/*
ump 'emailToName' is for mapping the name to each email. eg. {harsha@gmail.com, harsha}
ump 'graph' is for creating a adjList, we attach all the emails from 2 to n to 1st email
uset 'visited' is for not visiting any email again
2D 'result' vector is for storing the ans and returning it
For each unvisited email, we create a vector component and we run DFS and insert all the corresponding emails, it can be from 2 different entries, 
merging happens here in the DFS call. We sort it. We insert the name from the ump 'emailToName' at start and insert this into ans 2D vector

TC : building the adjList - O(E)
DFS - O(E+V)
Sorting takes - O( sum(Mi * log(Mi)) ), where sum() denotes the summation and ‘Mi’ denotes the length of accounts[i].
Sorting step dominates

SC  -  O(E)
*/

void dfs(const string& email, unordered_map<string, vector<string>>& graph, vector<string>& component, unordered_set<string>& visited) {
    visited.insert(email);
    component.push_back(email);
    for (const auto& u : graph[email]) {
        if (!visited.count(u)) {
            dfs(u, graph, component, visited);
        }
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> emailToName;      // {harsha@gmail.com, harsha}
    unordered_map<string, vector<string>> graph;    // adjList / creating edges from 1st email to all remaining emails

    // Build the graph and map email to name
    for (const auto& account : accounts) {
        const string& name = account[0];
        for (int i = 1; i < account.size(); ++i) {
            emailToName[account[i]] = name;
            if (i > 1) {
                graph[account[i]].push_back(account[1]);
                graph[account[1]].push_back(account[i]);
            }
        }
    }

    unordered_set<string> visited;
    vector<vector<string>> result;

    // DFS to find connected components
    for (const auto& it : emailToName) {
		string email = it.first;
        if (!visited.count(email)) {
            vector<string> component;
            dfs(email, graph, component, visited);
            sort(component.begin(), component.end());
            component.insert(component.begin(), emailToName[email]);
            result.push_back(component);
        }
    }

    return result;
}
