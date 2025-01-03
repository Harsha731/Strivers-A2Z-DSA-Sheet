/*
QUESTION:
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 
2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from 
node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting 
from that node leads to a terminal node (or another safe node).

APPROACH:
1. Initialize:
    Set all nodes' indegree to 0.
    Create a queue and push nodes with indegree 0.
    Initialize an empty safeNodes array.

2. Reverse Edges: Reverse the direction of all edges in the graph.
3. Calculate Indegree: For each edge u -> v, increment indegree[v].

4. BFS Traversal:
    While the queue is not empty:
        Pop a node, add to safeNodes.
        For each adjacent node v, decrement indegree[v].
        If indegree[v] == 0, push v to the queue.
5. Sort: Sort the safeNodes array.

COMPLEXITY ANALYSIS:
Time Complexity: O(V+E)+O(N*logN), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm. 
Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.

Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the indegree array, O(N) for the queue data structure 
used in BFS(where N = no.of nodes), and extra O(N) for the adjacency list to store the graph in a reversed order.
*/

// We have to remove the nodes in cycle as well as well as nodes leading to cycle
// The nodes have to be leading to always a terminal node, else don't consider them 
class Solution {
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			// i -> it
			// it -> i
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};
