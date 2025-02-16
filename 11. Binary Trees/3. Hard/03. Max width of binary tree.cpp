/* QUESTION:

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will be in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).


APPROACH:

Each node is paired with its index in a "virtual" complete binary tree.
For each level, the width is calculated as the difference between the first and last node's indices plus one.
Children are indexed as 2 x index + 1 (left) and 2 x index + 2 (right) relative to the current node's index.
Update the maximum width after processing each level.
Return the maximum width after traversing all levels.

COMPLEXITY ANALYSIS:

Let `n` be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n) since we need to traverse all nodes in the binary tree using BFS.
- Space Complexity: The space complexity is O(w) for the queue, where `w` is the maximum width of the binary tree at any level.

CODE:
*/

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    long long ans = 0;
    queue<pair<long long, TreeNode*>> q;
    q.push({0, root});

    while (!q.empty()) {
        int n = q.size();
        long long start = q.front().first;
        long long end = q.back().first;

        for (int i = 0; i < n; i++) {
            auto p = q.front();
            q.pop();
            // note we are doing -start because we don't need previous value
            long long index = p.first - start;
            TreeNode* curr = p.second;

            if (curr->left) q.push({2 * index + 1, curr->left});
            if (curr->right) q.push({2 * index + 2, curr->right});
        }

        ans = max(ans, end - start + 1);
    }

    return (int)ans;
}
