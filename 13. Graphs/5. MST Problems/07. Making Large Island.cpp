/*
QUESTION:-
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Approach:
1. Create a disjoint set to represent islands and initialize it with all cells.
2. For each 1 cell, union it with its 4-directionally connected 1 cells in the disjoint set.
3. Then, traverse the grid to find each 0 cell and count the size of connected islands that can be formed by changing this 0 to 1.
4. Update the answer with the maximum island size found so far.
5. Return the maximum island size.

Complexity Analysis:
- The time complexity of creating the disjoint set is O(n^2) as we need to initialize it with all cells.
- The time complexity of the first pass (connecting 1 cells) is also O(n^2) as we traverse the entire grid once.
- The time complexity of the second pass (counting island size for 0 cells) is O(n^2) as we again traverse the entire grid.
- The time complexity of finding the maximum island size using the disjoint set is O(n^2) as we iterate through all cells.
- Overall, the time complexity of the solution is O(n^2).
- The space complexity is O(n^2) due to the disjoint set data structure.

CODE:-
*/

/*
1) Connect all the 1's as components in step 1 by (row*n + col)
2) Use a 'set' to know different components along the 4 directions (edge case) for the cell, then do size increment accordingly and update max if possible
3) Edge case is if all 1's exists, then step 2 won't run
*/

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
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
        int uSize = size[uP], vSize = size[vP];
        if (uSize > vSize) {
            parent[vP] = uP;
            size[uP] += vSize;
        } else {
            parent[uP] = vP;
            size[vP] += uSize;
        }
    }
};

bool isLand(int i, int j, vector<vector<int>>& grid){
    return (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && grid[i][j] == 1);
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    DisjointSet djs(n * n);

    // step 1 : Connect all the 1's as components in step 1 by (row*n + col)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int id = i * n + j;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (isLand(ni, nj, grid)) {
                        int nid = ni * n + nj;
                        if (djs.findUPar(id) != djs.findUPar(nid))
                            djs.unionBySize(id, nid);
                    }
                }
            }
        }
    }

    // step 2 : Use a 'set' to know different components along the 4 directions (edge case) for the cell, 
    // then do size increment accordingly and update max if possible
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                unordered_set<int> st;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (isLand(ni, nj, grid)) {
                        int nid = ni * n + nj;
                        st.insert(djs.findUPar(nid));
                    }
                }
                int siz = 0;
                for (auto u : st)
                    siz += djs.size[u];
                ans = max(ans, siz + 1);
            }
        }
    }

    // Edge case is if all 1's exists, then step 2 won't run
    for (int cellNo = 0; cellNo < n * n; cellNo++) {
        ans = max(ans, djs.size[djs.findUPar(cellNo)]);
    }
    // Simply, the first cell may be sufficient
    // ans = max(ans, djs.size[djs.findUPar(0)]);
    
    return ans;
}
__________________________________________________

/* 
DFS / BFS approach
For every 0 present in the matrix, we re initialize vis = 0 and
we try to make it 1 and get the maxSize surrounding it

TC : O(N^4), where ‘N’ is the number of rows in the binary matrix. 
Since we are traversing over each element of the matrix, and we are calling DFS for every 0 encountered which 
takes O(N^2) time for each call. Hence, the overall Time Complexity is O(N^4).

SC : O(N^2), where ‘N’ is the number of rows in the binary matrix.
*/

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// DFS to find the island size
int getIslandSize(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || visited[i][j] || grid[i][j] == 0)
        return 0;
    
    visited[i][j] = true;
    int size = 1;
    for (int k = 0; k < 4; k++) {
        size += getIslandSize(grid, i + dx[k], j + dy[k], visited);
    }
    return size;
}

int maximumIslandSize(vector<vector<int>>& grid) {
    int n = grid.size(), maxSize = 0;
    bool hasZero = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                hasZero = true;
                grid[i][j] = 1;
                vector<vector<bool>> visited(n, vector<bool>(n, false));
                maxSize = max(maxSize, getIslandSize(grid, i, j, visited));
                grid[i][j] = 0;
            }
        }
    }

    return hasZero ? maxSize : n * n;
}
