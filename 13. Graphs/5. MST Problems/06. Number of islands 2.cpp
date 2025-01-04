/*
QUESTION:-
You are given an n x m 2D matrix, and an array of size k denoting the number of operations. The matrix elements are 0 
if there is water or 1 if there is land. Originally, the 2D matrix is all 0, which means there is no land in the matrix. 
The array has k operator(s) and each operator has two integers A[i][0], A[i][1], which means that you can change the 
cell matrix[A[i][0]][A[i][1]] from sea to an island. Return how many islands are there in the matrix after each operation. 
You need to return an array of size k.
Note: An island means a group of 1s such that they share a common side.

Example 1:
Input: n = 4, m = 5, k = 4, A = {{1,1},{0,1},{3,3},{3,4}}
Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
*/


/* 
Approach:
1. Create a disjoint set to represent islands.
2. Initialize an empty grid to track the islands.
3. For each operation (i.e., changing sea to land), do the following:
   a. If the cell is not already land, mark it as land and increment the island count.
   b. For the neighboring cells that are land, check if they belong to the same island or not.
      - If they don't belong to the same island, union the sets and decrement the island count.
4. Return the island count after each operation as the result.

Complexity Analysis:
- The time complexity of each operation is O(4 * alpha(n*m)) due to the union operation, where alpha(n*m) is the inverse Ackermann function.
- Since there are k operations, the overall time complexity is O(k * alpha(n*m)).
- The space complexity is O(n*m) for storing the grid and the disjoint set.

CODE:-
*/

/*
Initially all are water cells and k cells had been made as land
We increase 1 for each iteration and we can decrease 4 at max in each iteration by checking that does it make islands connecting or not
Each cell is represented as mx+y
*/

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionSize(int u, int v) {
        int up = findUPar(u), vp = findUPar(v);
        int us = size[up], vs = size[vp];
        if (us > vs) {
            parent[vp] = up;
            size[up] += vs;
        } else {
            parent[up] = vp;
            size[vp] += us;
        }
    }
};

bool isLand(int x, int y, vector<vector<int>>& grid) {
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1);
}

vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
    vector<int> ans;
    int islands = 0;
    DisjointSet djs(n * m);
    vector<vector<int>> grid(n, vector<int>(m, 0));

    vector<int> dr = { -1, 1, 0, 0 };
    vector<int> dc = { 0, 0, -1, 1 };

    for (auto op : operators) {
        int x = op[0], y = op[1];
        if (grid[x][y] != 1) {
            grid[x][y] = 1;
            islands++;
            int id = x * m + y;
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i], ny = y + dc[i];
                if (isLand(nx, ny, grid)) {
                    int nid = nx * m + ny;
                    if (djs.findUPar(id) != djs.findUPar(nid)) {
                        djs.unionSize(id, nid);
                        islands--;
                    }
                }
            }
        }
        ans.push_back(islands);
    }
    return ans;
}
_________________________________________________________

/*  DFS / BFS approach

    For every query, we are making vis array to 0 again. We are counting that how many times do we need to run DFS / BFS for the current scenario

    Time Complexity : O(Q * N * M)
    Space Complexity : O(N * M)

    Where 'Q' is the number of queries.
    Where 'N' is the number of rows and 'M' is the number of columns.
*/

bool valid(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis){
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y] == 1){
		return 0;
	}

	return 1;
}

void dfs(int x, int y, vector<int> &dx, vector<int> &dy, vector<vector<int>> &grid, vector<vector<int>> &visited){
	visited[x][y] = 1;

	for (int dir = 0; dir < 4; dir++){
		int X = x + dx[dir], Y = y + dy[dir];

		if (!valid(X, Y, grid.size(), grid[0].size(), grid, visited)){
			continue;
		}
		dfs(X, Y, dx, dy, grid, visited);
	}
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	vector<int> ans;
	vector<vector<int>> grid(n, vector<int>(m));

	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};

	for (int i = 0; i < (int)q.size(); i++){
		int x = q[i][0], y = q[i][1];

		grid[x][y] = 1;

		int noOfIslands = 0;

		vector<vector<int>> visited(n, vector<int>(m));

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (grid[i][j] == 1 && !visited[i][j]){
					dfs(i, j, dx, dy, grid, visited);
					noOfIslands++;
				}
			}
		}
		ans.push_back(noOfIslands);
	}
	return ans;
}
