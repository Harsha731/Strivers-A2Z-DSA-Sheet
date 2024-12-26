/**
 * Question: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

 * Approach:
 * 1. Use backtracking to solve the n-queens puzzle.
 * 2. Start with an empty chessboard and try placing queens in each row, ensuring that no two queens threaten each other.
 * 3. Use row, column, and diagonal constraints to validate the queen placements.
 * 4. If a valid configuration is found, add it to the list of solutions.
 *
 * Time Complexity: O(N!), where N is the input parameter representing the size of the chessboard.
 *   - In the worst case, there can be N! possible configurations to check.
 *   - However, with the pruning technique used in backtracking, the actual runtime is much less than N! in most cases.
 *
 * Space Complexity: O(N^2), where N is the input parameter representing the size of the chessboard.
 *   - The space is used to store the chessboard configuration and the auxiliary arrays for tracking the used columns and diagonals.
 */

class Solution {
public:
    vector<vector<string>> ret;

    bool is_valid(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q' 
                || (col - row + i >= 0 && board[i][col - row + i] == 'Q') 
                || (col + row - i < board.size() && board[i][col + row - i] == 'Q') )  return false;
        return true;
    }

    void dfs(vector<string>& board, int row) {
        if (row == board.size()) {
            ret.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); ++col) {
            if (is_valid(board, row, col)) {
                board[row][col] = 'Q';
                dfs(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return {};
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return ret;
    }
};
