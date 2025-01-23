/*
QUESTION:
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

APPROACH:
- This problem can be solved using dynamic programming.
- We need to find the largest square containing only 1's.
- Define a 2D DP array `dp` where dp[i][j] represents the side length of the largest square ending at (i, j).
- The base case is dp[i][0] = matrix[i][0] and dp[0][j] = matrix[0][j].
- Iterate through each cell (i, j) in the matrix starting from (1, 1).
- If matrix[i][j] is '1', update dp[i][j] as the minimum of (dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1.
- Update the maximum side length `maxSide` accordingly.
- Return `maxSide * maxSide`, which is the area of the largest square containing only 1's.

COMPLEXITY ANALYSIS:
- The time complexity of this approach is O(m * n), where m is the number of rows and n is the number of columns in the matrix.
- The space complexity is O(m * n) due to the dp array.
- Overall, the algorithm runs in O(m * n) time and O(m * n) space.

CODE:
*/

int ftab(int m, int n, vector<vector<char>>& matrix){
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxSide = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i-1][j-1] == '1'){
                int temp = min(dp[i-1][j], dp[i-1][j-1]);
                dp[i][j] = min(dp[i][j-1], temp) + 1;    // The min of the three is being done
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    return ftab(m, n, matrix);
}
_______________________________________

// The question is actually this one, not the above code. But the above may also ask a few times
// This appraoch if from Stacks and Queues and it is for Rectangle, not square

/*
QUESTION:
Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

APPROACH:
To solve this problem, we can use a variation of the Largest Rectangle in Histogram problem.
1. First, we will calculate the heights of the histogram for each row in the matrix.
   - If the current element is '1', we increment the height of the histogram at that column by 1.
   - If the current element is '0', we reset the height of the histogram at that column to 0.
2. For each row, we calculate the largest rectangle area using the heights calculated in step 1.
   - We use the largestRectangleArea function, which calculates the largest rectangle area in a histogram.
   - The histogram heights are the heights of the current row up to that column.
3. Finally, we return the maximum area obtained from step 2.

Example:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

CODE:
*/

/*
There are other methods in DP as well
We convert this question into Largest Rectangle in Histogram by storing each row values along with the top row
Here, we use prev and next Smaller arrays
TC : O(n*m) as we iterate through each element 
SC : O(m) -> O(1) if we modify the input array
*/

// Helper function to calculate the previous smaller element index for each element in an array
vector<int> prevSmaller(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// Helper function to calculate the next smaller element index for each element in an array
vector<int> nextSmaller(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// Function to calculate the largest rectangle area in a histogram represented by heights
int largestRectangleArea(vector<int>& heights) {
    vector<int> prev = prevSmaller(heights);
    vector<int> next = nextSmaller(heights);

    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++) {
        ans = max(ans, (next[i] - prev[i] - 1) * heights[i]);
    }
    return ans;
}

// Function to find the largest rectangle area in a binary matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> prev(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        vector<int> curr(cols, 0);
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                curr[j] = prev[j] + 1;
        }

        int rowArea = largestRectangleArea(curr);
        maxArea = max(maxArea, rowArea);

        prev = curr;
    }

    return maxArea;
}


/*
COMPLEXITY ANALYSIS:
- Let n be the total number of elements in the matrix, and m be the number of columns.
- The time complexity of the solution is O(n*m) because we iterate through each element of the matrix once.
- The space complexity is O(m) since we use additional arrays to store the heights and indices during the calculation.
  However, the space complexity can be considered O(1) if we modify the input matrix directly.
*/
