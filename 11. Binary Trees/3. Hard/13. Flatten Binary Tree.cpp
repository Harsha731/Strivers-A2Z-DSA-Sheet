/* QUESTION:

Given the root of a binary tree, flatten the tree into a "linked list".

APPROACH 1:

/*
https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
Check the brute force approach
To understand the links formation and breakage

First, we go right subtree, then left subtree. We do for right, then for left, then attach root to them
Each time, When we are going from right to left subtree, we are making the rightmost node of left subtree
link to right child of root
The right sub-tree will be having prev at the top, so during link formation, we attach to this 'prev'
At the end, root will be prev

TC : O(N) and SC : O(logN) for stack space
*/

class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
______________________________________________________

APPROACH 2:

/*
https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
-> Iterative Traversal with Stack: While the stack is not empty, repeat the following steps:
Pop the top node from the stack.
If the popped node has a right child, push it onto the stack. This ensures that the right child is processed after the left child nodes.
If the popped node has a left child, push it onto the stack.
If the stack is not empty after pushing the left child, connect the right pointer of the current node (popped from the stack) to the top node of the stack. This creates the linked list structure by setting the next pointer.
Set the left pointer of the current node to null as we have to form a right skewed linked list.
*/

class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        stack<TreeNode*> st;
        st.push(root);  
        
        while (!st.empty()) {  
            TreeNode* cur = st.top(); 
            st.pop();  

            if (cur->right != NULL) st.push(cur->right); 
            if (cur->left != NULL) st.push(cur->left); 

            if (!st.empty()) cur->right = st.top();  
            
            cur->left = NULL;  
        }
    }
};

_________________________________________

APPROACH 3:

https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
To flatten the binary tree into a linked list, we can modify the tree in-place using a modified preorder traversal.

1. We start with the current node as the root.
2. While the current node is not NULL, we do the following:
   - If the current node has a left child, we find the rightmost node of its left subtree.
     - We make the right child of the rightmost node point to the right child of the current node.
     - We set the left child of the current node to NULL.
     - We set the right child of the current node to its left child.
   - We move to the right child of the current node.
3. We repeat this process until we have visited all the nodes in the tree.

COMPLEXITY ANALYSIS:

Let n be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n) since we visit each node once.
- Space Complexity: The space complexity is O(1) since we don't use any extra space.

CODE:
*/

void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            TreeNode* temp = curr->left;
            while (temp->right)
                temp = temp->right;

            temp->right = curr->right;
            curr->left = NULL;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}
