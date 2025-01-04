/*
QUESTION:-
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
*/

/* 
DFS + binary search approach
Binary Search: Used to find the minimum time required (low to high range) to swim from top-left to bottom-right.
DFS: The canReach function performs depth-first search to check if the target can be reached with the current mid value.
Visited Array: Prevents revisiting cells during DFS, ensuring correctness and avoiding infinite loops
TC : O(N^2 logN) as Binary search runs at max log(N^2) times and it runs DFS for N^2 iterations for each DFS
*/
class Solution {
    int n;

    bool canReach(int row, int col, vector<vector<int>>& grid, int dr[], int dc[], int depth, vector<vector<bool>>& visited) {
        if (row == n - 1 && col == n - 1)
            return true;

        visited[row][col] = 1;
        
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] <= depth) {
                if (canReach(nr, nc, grid, dr, dc, depth, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0, high = 0;
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = max(high, grid[i][j]);
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, 0));
            if (grid[0][0] <= mid && canReach(0, 0, grid, dr, dc, mid, visited)) {      // It is possible, now we check for lower time
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};
____________________________

/* BFS + Priority Queue
Priority Queue (Min-Heap): Used to process cells in increasing order of elevation, ensuring the minimum elevation path is considered.
Visited Array: Prevents revisiting cells, ensuring each cell is processed only once.
Dynamic Elevation (ans): Tracks the maximum elevation encountered on the current path, as the result is determined by the highest elevation on the path.
TC : O(N^2 log(N^2) ) = O(N^2logN) as N^2 elements in worst case in PQ and N^2 elements need to be traversed
SC : O(N^2)
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        
        vector<int> drow = {-1, 1, 0, 0};  // Up, Down, Left, Right
        vector<int> dcol = {0, 0, -1, 1};  
        
        pq.push({ans, 0, 0});
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + drow[i], c = cur[2] + dcol[i];
                
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }
        
        return -1;
    }
};
_________________________________________________

/*
The priority queue processes grid cells in increasing order of elevation, ensuring we always handle the least water level next.
The union-find data structure tracks connected cells and determines if the top-left and bottom-right cells are connected.
For each processed cell, we attempt to union it with neighboring cells that are within bounds and unvisited.
We are finding the path which takes us to botoom right with min possible elevation

Time Complexity: O(n^2 * log n) due to the priority queue and union-find operations.
Space Complexity: O(n^2) for the priority queue, visited matrix, and union-find data structures.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        return unionFindSwimInWater(grid);
    }

private:
    int unionFindSwimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        // Priority queue to process cells in increasing order of elevation
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        // Directions for moving up, down, left, right
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};

        // Initialize priority queue with the top-left corner
        pq.push({grid[0][0], 0, 0});
        
        // Set of visited cells
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        while (!pq.empty()) {
            auto [elevation, row, col] = pq.top();
            pq.pop();

            // Try to union the current cell with its neighbors
            for (int k = 0; k < 4; k++) {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if (isWithinBounds(newRow, newCol, n) && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    pq.push({grid[newRow][newCol], newRow, newCol});
                    ds.unionSets(row * n + col, newRow * n + newCol);
                }
            }

            // If top-left and bottom-right are connected, return the current elevation
            if (ds.find(0) == ds.find(n * n - 1)) {
                return elevation;
            }
        }

        return -1; // Should never reach here
    }

    bool isWithinBounds(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
};
