/*
QUESTION:-
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

APPROACH:
- We can use a Breadth-First Search (BFS) traversal to find the distance of the nearest 0 for each cell.
- First, we initialize the distance matrix with -1 for all cells.
- Then, we iterate through the matrix and find all cells with the value 0. For each 0 cell found, we add it to the queue and set its distance to 0 in the distance matrix.
- Next, we perform a BFS starting from the cells with 0. During the BFS, we update the distance of each cell from the nearest 0 cell and continue the BFS until all cells are visited.
- Finally, we return the distance matrix.

COMPLEXITY ANALYSIS:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. In the worst case, we may need to visit all the cells of the matrix.
- Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. We use additional space for the distance matrix and the queue during BFS.
*/

/* Notes :
BFS question
Nearest 0's in LC (here) and nearest 1's in striver blog
vis and dis 2D matrices are used
We insert all the 0's into queue with nearest 0 distance as 0 and vis = 1
We go in 4 directions and check if vis = 0 and mat[i][j] = 1
At last we stop after going to all the nodes in matrix
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(); 
    int n = mat[0].size();
    vector<vector<int>> dis(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    int level = 1;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int nx = x + dr[i], ny = y + dc[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && dis[nx][ny] == -1){
                    dis[nx][ny] = level;
                    q.push({nx, ny});
                }
            }
        }
        level++;
    }

    return dis;
}
______________________________________________

// Not optimal - unneccesary DFS calls are being made here, TLE comes

void dfs(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& dis, int dist) {
    if (x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size() || dis[x][y] <= dist)
        return;

    dis[x][y] = dist;

    dfs(x - 1, y, mat, dis, dist + 1); // up
    dfs(x + 1, y, mat, dis, dist + 1); // down
    dfs(x, y - 1, mat, dis, dist + 1); // left
    dfs(x, y + 1, mat, dis, dist + 1); // right
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dfs(i, j, mat, dis, 0);
            }
        }
    }

    return dis;
}
