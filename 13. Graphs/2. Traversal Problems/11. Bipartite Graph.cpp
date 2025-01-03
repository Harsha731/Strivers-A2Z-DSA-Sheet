/*
QUESTION:
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
1. There are no self-edges (graph[u] does not contain u).
2. There are no parallel edges (graph[u] does not contain duplicate values).
3. If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

APPROACH:
Use !col to get alternate colors and a col vector to store
Here, 3 cases - uncolored and colored (already visited) but different color and colored with same color
uncoloured - do proceed
colored(already visited) but different colour - no problem
same colour - return false
We are searching for atleast one false
Use bool dfs here

COMPLEXITY ANALYSIS:
Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
Space Complexity: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list.
*/

class Solution {
private: 
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, adj)) return false; 
            } else if (color[it] == col) {
                return false; 
            }
        }
        return true; 
    }

public:
    bool isBipartite(int V, vector<int> adj[]) {
        int color[V];
        for (int i = 0; i < V; i++) color[i] = -1; 
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, adj)) return false; 
            }
        }
        return true; 
    }
};

