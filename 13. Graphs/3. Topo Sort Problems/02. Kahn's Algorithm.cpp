/*
QUESTION:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

APPROACH:
- We can use Topological Sorting to check if a directed graph contains a cycle or not.
- If a directed graph is a DAG (Directed Acyclic Graph), it means it does not contain any cycle.
- So, to check for a cycle, we perform a variation of Topological Sorting using Kahn's algorithm, which is based on the concept of indegree.
- If there is no cycle in the graph, we can always find a node with an indegree of 0 (no incoming edges) and remove it along with its outgoing edges.
- We keep repeating this process, and if at any point we are unable to find a node with an indegree of 0, it means there is a cycle in the graph.

COMPLEXITY ANALYSIS:
- Time Complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. We perform a BFS-like traversal of all nodes and edges.
- Space Complexity: O(V), where V is the number of vertices (nodes) in the graph. We use additional space to store the indegree of each node and the queue for BFS.
*/

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;        // ( i -> it ) is a edge
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
};


