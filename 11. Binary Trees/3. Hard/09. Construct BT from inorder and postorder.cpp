/* QUESTION:

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

APPROACH:

The postorder traversal follows the left-right-root order, while the inorder traversal follows the left-root-right order. Based on these two traversals, we can construct the binary tree recursively.

1. The last element in the postorder traversal array is the root of the binary tree.
2. We can find the position of the root in the inorder traversal array. All the elements to the left of this position will be in the left subtree, and all the elements to the right will be in the right subtree.
3. Recursively, we can build the left and right subtrees using the corresponding portions of the inorder and postorder traversal arrays.
4. The recursive function takes the index of the current element in the postorder traversal array, the starting and ending indices of the current portion in the inorder traversal array, and the inorder and postorder traversal arrays as inputs.
5. In each recursive call, we create a new node with the value of the current element in the postorder traversal array and determine its left and right subtrees by calling the recursive function on the corresponding portions of the inorder and postorder traversal arrays.
6. The base case is when the starting index is greater than the ending index, indicating an empty portion of the tree. In this case, we return NULL.
7. Finally, we return the root of the constructed binary tree.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n), as we visit each node once.
- Space Complexity: The space complexity is O(n) for the recursive call stack.

CODE:
*/

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size()) {
        return NULL;
    }

    map<int, int> hm;
    for (int i = 0; i < inorder.size(); i++) {
        hm[inorder[i]] = i;
    }

    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
}

TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& hm) {

    if (ps > pe || is > ie) {
        return NULL;
    }

    TreeNode* root = new TreeNode(postorder[pe]);
    int inRoot = hm[postorder[pe]];
    int numsLeft = inRoot - is;

    root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);

    root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

    return root;
}

