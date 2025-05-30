/* QUESTION:

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] 
represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, 
and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

APPROACH:
- We can use the Disjoint Set data structure to keep track of connected components and find the minimum number of times we need to add connections.
- If the number of connections is less than n - 1 (number of computers minus one), it means the network is disconnected, 
and we cannot make all the computers connected. In this case, we return -1.
- Otherwise, we initialize a Disjoint Set data structure with n nodes representing each computer.
- We iterate through the given connections and union the connected components of each pair of computers using the Disjoint Set data structure.
- After this, we count the number of disconnected components using the findUPar function of the Disjoint Set data structure.
- The minimum number of times we need to add connections to make all computers connected is the number of disconnected components minus one.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(E + V), where E is the number of connections and V is the number of computers. 
The log V factor is due to the unionBySize operation in the Disjoint Set data structure.
- The space complexity is O(V) for the Disjoint Set data structure and other data structures.

CODE:
*/

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uP = findUPar(u), vP = findUPar(v);
        int uPSize = size[uP], vPSize = size[vP];
        if (uPSize > vPSize) {
            parent[vP] = uP;
            size[uP] += vPSize;
        } else {
            parent[uP] = vP;
            size[vP] += uPSize;
        }
    }

    int disconnected(int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if (n - 1 > connections.size())
        // If we have wires less than n-1, then it is not possible to conenct the n computers
        return -1;

    DisjointSet djs(n);
    for (auto c : connections) {
        int u = c[0], v = c[1];
        if (djs.findUPar(u) != djs.findUPar(v))
            djs.unionBySize(u, v);
    }

    int ans = djs.disconnected(n);
    return ans - 1;
}
_______________________________________________________

/*
DFS / BFS approach
We are checking at start, m < n-1
Then, we are counting the no. of BFS traversals needed. so, cnt - 1 is answer

Time Complexity : O(N + M), where N denotes the number of vertices and M denotes the number of edges in the graph.
We are visiting each vertex and edge once.

Space Complexity : O(N + M), where N denotes the number of vertices and N denotes the number of edges in the graph.
We build an adjacency list where ‘i-th’ vector/list can be of size N.
*/  
int makeGraphConnected(int n, vector<pair<int, int>>& edges, int m) {
    if (m < n - 1) return -1;

    vector<int> adj[n + 1];
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<bool> vis(n + 1, false);
    int ctr = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            queue<int> q;
            vis[i] = true;
            q.push(i);
            ctr++;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    return ctr - 1;
}
