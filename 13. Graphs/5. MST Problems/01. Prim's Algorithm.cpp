/* QUESTION:

Given a weighted, undirected and connected graph of V vertices and E edges, the task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Example:

Input: 
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.

APPROACH:
- We will use Prim's algorithm to find the Minimum Spanning Tree (MST) of the graph.
- The idea is to start from any vertex (let's say vertex 0) and add it to the MST.
- Then, we will add the edges connected to vertex 0 to a priority queue (min-heap), where the edges are sorted based on their weights in ascending order.
- We will keep adding the edges with the minimum weight to the MST and add their connected vertices to the priority queue if they are not already in the MST.
- We will repeat this process until all vertices are added to the MST.

COMPLEXITY ANALYSIS:
- The time complexity of Prim's algorithm is O(V^2) using an adjacency matrix representation, where V is the number of vertices.
- If an adjacency list representation is used, the time complexity reduces to O(E + V log V), where E is the number of edges and log V is the time complexity of priority queue operations.
- The space complexity is O(V) for the priority queue and other data structures.

CODE:
*/

class Solution {
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		int sum = 0;
		pq.push({0, 0});
        
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};
____________________________________
/*
Obtaining the info about the MST instead of simply sum of edges in MST

Note: Points to remember if we do not wish to store the mst(minimum spanning tree) for the graph and are only concerned 
   about the sum of all the edge weights of the minimum spanning tree:
First of all, we will not use the triplet format instead, we will just use the pair in the format of 
   (edge weight, node value). Basically, we do not need the parent node.
In step 3, we need not store anything in the mst array and we need not even use the mst array in our whole algorithm as well.
*/
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[], vector<pair<int, int>>& mstArray)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector<int> vis(V, 0);
        // {edge weight, node, parent}
        int sum = 0;
        pq.push({0, 0, -1});  

        while (!pq.empty()) {

            // auto it = pq.top();
            // int wt = get<0>(it);  
            // int node = get<1>(it);  
            // int parent = get<2>(it);  

            auto [wt, node, parent] = pq.top();  // Structured bindings to unpack the tuple
            pq.pop();

            if (vis[node] == 1) continue;  // Skip if already visited
            vis[node] = 1;
            sum += wt;

            // Store the edge {node, parent} in the MST array, if not the starting node
            if (parent != -1) {
                mstArray.push_back({node, parent});
            }

            // Add all unvisited adjacent nodes to the priority queue
            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor[0];  // adjacent node
                int edW = neighbor[1];  // edge weight

                if (!vis[adjNode]) {
                    pq.push({edW, adjNode, node});  // Push with edge weight, adjacent node, and parent node
                }
            }
        }
        return sum;
    }
};
