/* QUESTION:

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

APPROACH:

Base Case: If the current range is invalid (preStart > preEnd or inStart > inEnd), return NULL.
Root Identification: The root is the first element in the preorder array. Find its index in the inorder array using the map.
Divide Tree: Use the root’s index to divide the tree into left and right subtrees.
Recursion: Recursively build the left and right subtrees by adjusting the range of the preorder and inorder arrays.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n), as we visit each node once.
- Space Complexity: The space complexity is O(n) for the recursive call stack.

CODE:
*/

TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}

