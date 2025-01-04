/*
QUESTION:-
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Check the Image

Approach:
1. We can use Kosaraju's algorithm to find the number of strongly connected components (SCCs) in a directed graph.
2. Kosaraju's algorithm performs two DFS traversal on the graph to find SCCs.
3. In the first DFS traversal, we find the order of vertices in which they finish their DFS traversal (topological ordering).
4. In the second DFS traversal, we visit the vertices in reverse order of their finish times (based on the first DFS traversal) 
and mark the SCCs.
5. The number of SCCs will be the number of times we perform the second DFS traversal and find a new SCC.

Complexity Analysis:
- Let V be the number of vertices and E be the number of edges in the directed graph.
- The time complexity of Kosaraju's algorithm is O(V + E) as we perform two DFS traversals.
- The space complexity is O(V + E) to store the adjacency list and O(V) for the auxiliary arrays.

Image : 
In the first image, we have the graph. If we reverse the graph, and if we traverse in the same toposort order
0 1 2 | 3 | 4 5 6 | 7     
Starting from 0, we end up in the same SCC, again we need to start DFS from 3 and again from 4 and again from 7
It is because, SCC1 -> SCC2 are only 1 sided, more than 1 can be there, thatswhy they are 2 different SCC's
Now, by reversing, we can't go from SCC1 to SCC2, we need to start again

Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. 
The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph 
and the third step, containing DFS again, will take O(V+E) each.

Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the 
visited array and the stack we have used. O(V+E) space for the reversed adjacent list.

*/


void topo(int node, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = true;
    for (auto v : adj[node]) {
        if (!vis[v]) {
            topo(v, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs(int node, vector<bool>& vis, vector<int> revadj[]) {
    vis[node] = true;
    for (auto v : revadj[node]) {
        if (!vis[v]) {
            dfs(v, vis, revadj);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> vis(V);
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            topo(i, vis, adj, st);
    }

    vector<int> revadj[V];
    for (int i = 0; i < V; i++) {
        for (auto j : adj[i]) {
            revadj[j].push_back(i);
        }
    }

    int ans = 0;
    vector<bool> visi(V);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visi[node]) {
            dfs(node, visi, revadj);
            ans++;
        }
    }
    return ans;
}
