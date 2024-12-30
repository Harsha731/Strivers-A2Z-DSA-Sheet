/*
QUESTION:-

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

/*
APPROACH:-

https://lh4.googleusercontent.com/Xq3R-xwSRxUx3EEjKQIMaHTM9qGqj81nPFe2nGoSnxnd36bStjU989Sf-CsWAnFZf4jHS68xr4l49QqKXeo7o7lLF1V38SJYaxC1CWWNzvk-eBNevdWhduS6mBSX9QGXGATwQw0OkFXkP18JWw
![Sample Output](Spiral_traversal.png)

In each outer loop traversal print the elements of a square in a clockwise manner.
Print the top row, i.e. Print the elements of the top row from column index left to right and increase the count of the top so that it will move to the next row.
Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.
Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left and decrease the count of bottom
Print the left column, i.e. if left <= right, then print the elements of the left column from the bottom row to the top row and increase the count of left.
Run a loop until all the squares of loops are printed.

*/

// CODE:

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(); 
    int m = matrix[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

// TIME COMPLEXITY: O(N), where N is the total number of elements in the matrix.
// SPACE COMPLEXITY: O(1)
