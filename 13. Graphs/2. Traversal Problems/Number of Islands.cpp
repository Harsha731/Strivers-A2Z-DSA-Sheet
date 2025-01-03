/*
here, we traverse in 8 directions instead 4
also, here island can be touching to boundary as well
so, check mat[][] = 1 and vis = 0 for all M*N elements and run BFS or DFS on them
At the end, how many times we are able to do BFS / DFS is the answer

Time Complexity ~ O(N² + NxMx9), N² for the nested loops, and NxMx9 for the overall DFS of the matrix, that will happen throughout if all the cells are filled with 1.
Space Complexity: O(N²) for visited array max queue space O(N²), If all are marked as 1 then the maximum queue space will be N².
*/

class Solution {
private: 
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        vis[row][col] = 1; 
        queue<pair<int, int>> q;
        q.push({row, col}); 
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        while (!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow; 
                    int ncol = col + delcol; 
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                        && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1; 
                        q.push({nrow, ncol}); 
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int cnt = 0; 
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++; 
                    bfs(row, col, vis, grid); 
                }
            }
        }
        return cnt; 
    }
};
