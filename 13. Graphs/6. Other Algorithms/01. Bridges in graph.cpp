/*
Check Image
We do checking of bridges while backtracking

There are 3 cases :
i) The adjNode is parent node. Ignore it.
ii) The adjNode is not parent node and visited. Update the low[]. 
iii) The adjNode is not parent node and not visited till now. Do DFS and update the low.

We update the low in both cases of visited as well as unvisited (during backtracking)

we check whether we can reach earlier or to the parent node via another path

vector<vector<int>> adj(n); is the correct way of declaration

Here we are assuming the whole is connected graph, else we have to run DFS for every unvisited node

We are not considering the parent’s insertion time during calculating the lowest insertion time 
as we want to check if any other path from the node to the parent exists excluding the edge we intend to remove.
*/
______________________

int time;

void dfs(int node, int parent, int tin[], int low[], vector<int> adj[], vector<vector<int>>& ans, vector<bool>& vis) {
    vis[node] = true;
    low[node] = tin[node] = time;
    time++;

    for (auto v : adj[node]) {
        if (v == parent) continue;
        if (vis[v]) {
            low[node] = min(low[node], low[v]);
        } else {
            dfs(v, node, tin, low, adj, ans, vis);
            low[node] = min(low[node], low[v]);
            if (low[v] > tin[node])
                ans.push_back({v, node});
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    time = 0;
    vector<int> adj[n];
    for (auto c : connections) {
        adj[c[0]].push_back(c[1]);
        adj[c[1]].push_back(c[0]);
    }
    vector<vector<int>> ans;
    vector<bool> vis(n);
    int tin[n], low[n];
    dfs(0, -1, tin, low, adj, ans, vis);
    return ans;
}
