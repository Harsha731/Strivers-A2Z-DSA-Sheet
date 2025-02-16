/*
Question:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Approach 1:
- We can calculate the maximum depth of a binary tree recursively by traversing its left and right subtrees.
- The maximum depth of a tree is equal to the maximum of the maximum depths of its left and right subtrees, plus 1 for the root node.

Approach 2: Level Order Traversal - iterative approach

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(H), where H is the height of the binary tree. In the worst case, the tree can be skewed and have a height of N, resulting in O(N) space complexity. In the best case, the tree is balanced and has a height of log(N), resulting in O(log(N)) space complexity.

Code:
*/

int maxDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}
