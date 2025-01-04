/*

Articulation Points of a graph are the nodes on whose removal, the graph breaks into multiple components. 
Earlier it is edges, now it is of nodes

(1) => Earlier, we are talking about removal of bridge from node->it, so, node needs to reach it via another path
But here, We are removing the node, so in the node->it, it should be reached by a node earlier node. Hence even if the it is being reaching node via another path,
it is useless here

(2) => Earlier, it is low[node] = min(low[node], low[it])
But now low[it] -> tin[it], it is because, if the 2 is removed, we are able to reach the node 5 from only node 2 (tin[it]) at max and not from node 1 (low[it])

(3) => A node can become as AP for more than once, so we use hash array to mark it 
We may also use a set for it

(4) Child variable is used only for checking the starting point as AP or not

low[node] = min(low[node], low[it]);  // For unvisited or while backtracking
low[node] = min(low[node], tin[it]);  // For visited

In the image, 2 is AP because, low[4] = 3 and tin[2] = 3, so 4 is being reached at max from 2 only, so when we remove 2, it becomes disconnected
Also, 0 is AP, because child = 2    

Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
Space Complexity: O(3V), where V = no. of vertices. O(3V) is for the three arrays i.e. tin, low, and vis, each of size V.
*/

__________________________________

class Solution {
private:
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int>adj[], vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int>& mark) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;         					 //new  (4)
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0) {
                dfs(it, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[it]);        // same
                // node -- it
                if(low[it] >= tin[node] && parent!=-1){         //new   [ > is changed to >= ]  (1)
                    mark[node] = 1;
                }
                child++;      					  //new
            }
            else{
                low[node] = min(low[node], tin[it]);		//new [ min(low[node], low(it)) ] is there in bridges question]  (2)
            }
        }
        if(parent==-1 && child>1) mark[0] = 1;    		  //new
    }    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);

        vector<int> mark(V, 0);  				  //new     (3)

        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i, -1, adj, vis, tin, low, mark);
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
