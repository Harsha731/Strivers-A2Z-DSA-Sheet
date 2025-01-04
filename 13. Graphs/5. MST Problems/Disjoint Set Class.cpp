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
private:
    vector<int> parent, size, rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        // iota(parent.begin(), parent.end(), 0); instead of for loop
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

     void unionByRank(int x, int y) {
        int ulp_x = find(x);
        int ulp_y = find(y);
        if (ulp_x == ulp_y) return;
        if (rank[ulp_x] < rank[ulp_y]) {
            parent[ulp_x] = ulp_y;
        }
        else if (rank[ulp_y] < rank[ulp_x]) {
            parent[ulp_y] = ulp_x;
        }
        else {
            parent[ulp_y] = ulp_x;
            rank[ulp_x]++;
        }
    }

    void unionBySize(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    void printArrays() {
        cout << "PARENT" << endl;
        for (auto it : parent) {
            cout << it << " ";
        }
        cout << endl << "SIZE" << endl;
        for (auto it : size) {
            cout << it << " ";
        }
    }

    int setSize(int vertex) {
        return size[find(vertex)];
    }

    int numberOfDisjointSets(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = find(i);
        }

        set<int> uniqueParents;
        for (int i = 0; i < n; i++) {
            uniqueParents.insert(parent[i]);
        }
        return uniqueParents.size();
    }
};
