/*
Disjoint set

Union by Rank, Union by size

O(V+E) if done by BFS or DFS to tell connected or not. It is brute force approach
But, Disjoint set tells in O(1)

The disjoint Set data structure is generally used for dynamic graphs. 

2 arrays - Rank and Parent (ultimate parent actually)

We will connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. But if the ranks are equal, 
we can connect any parent to the other parent and we will increase the rank by one for the parent node to whom we have connected the other one.

The reason is, for the smaller rank one, path compression time becomes relatively lesser than in the previous case

Path compression technique helps to find the ultimate parent in O(1) otherwise O(logN)
It appears that we are changing ranks, but it won't get changed
This process is done using the backtracking method.

Note: The actual time complexity of union by rank and union by size and findPar() is O(4) which is very small and close to 1. 
So, we can consider 4 as a constant. Now, this 4 term has a long mathematical derivation which is not required for an interview.

The ranks get distorted after joining two components, so it is good to use union by Size
*/
______________________________________

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }   
        // iota(parent.begin(), parent.end(), 0); instead of for loop
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
