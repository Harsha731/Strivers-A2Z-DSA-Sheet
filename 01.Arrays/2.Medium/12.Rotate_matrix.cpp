/*
QUESTION:-

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/

/*
APPROACH:-

brute force) Take another matrix and keep the 1st row elements as 1st column elements and so on
Return the new matrix as ans
TC : O(N^2) and SC : O(N^2)

optimal) 

Given matrix :
a11 a21 a31 a41
a12 a22 a32 a42
a13 a23 a33 a43
a14 a24 a34 a44

Transposed matrix :
a11 a12 a13 a14
a21 a22 a23 a24
a31 a32 a33 a34
a41 a42 a43 a44

Reverse each row : (90 degrees CW)
a14 a13 a12 a11 
a24 a23 a22 a21
a34 a33 a32 a31
a44 a43 a42 a41

Reverse each col : (90 degrees CCW)
a41 a42 a43 a44
a31 a32 a33 a34
a21 a22 a23 a24
a11 a12 a13 a14

*/

// CODE: 

void rotate(vector<vector<int>>& matrix) {
    // Transpose the matrix
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){
        // note here we move 
        for(int j=0; j<i; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

// TIME COMPLEXITY = O(N^2), where N is the size of the matrix.
// SPACE COMPLEXITY = O(1)
