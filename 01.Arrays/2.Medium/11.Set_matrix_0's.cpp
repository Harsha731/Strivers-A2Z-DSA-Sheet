/*
QUESTION:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Set Matrix Zeros :
Brute force) Traverse each cell.
If a cell contains 0, set all 'non-zero' elements in its entire row and column to -1 using markRow and markCol.
Now, 2nd traversal is replacing every -1 with 0.
TC : O(N*M*(N+M)) + O(N*M) and SC : O(1)

Better approach) Arrays row and col are used to track which rows and columns need to be zeroed.
Traverse the matrix. If any element is 0, mark the corresponding row[i] and col[j] as 1.
Traverse the matrix again. Set matrix[i][j] to 0 if row[i] or col[j] is 1.
TC : O(N*M) and SC : O(N+M)

Optimal approach)
i) Instead of separate arrays for rows and columns, use the first row and column of the matrix itself.
ii) Additionally, use a variable col0 to track whether the first column should be zeroed.
Traverse the matrix. If a cell is 0, set the corresponding row marker (matrix[i][0]) and column marker (matrix[0][j]). If the zero is in the first column, set col0 to 0.
iii) Traverse the matrix from (1,1) to (n-1, m-1). Set matrix[i][j] to 0 if its row or column marker is 0.
iv) If the top-left cell (matrix[0][0]) is 0, zero out the entire first row. If col0 is 0, zero out the entire first column.
TC : O(N*M) and SC : O(1)

*/

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

