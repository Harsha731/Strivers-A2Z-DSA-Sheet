/*
Question:
Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/

/* 
Push Root to Stack: Start traversal by pushing the root onto the stack.
Iterative Traversal:
    • Process Node: Pop the top node from the stack and add its value to the result.
    • Right Child: If it exists, push the right child onto the stack.
    • Left Child: If it exists, push the left child onto the stack (it gets processed before the right child).
Return Result: Once the stack is empty, return the preorder traversal result.

TC : O(N) and SC : O(N)
*/ 

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        
        if(root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            root = st.top();
            st.pop();
            
            preorder.push_back(root->val);
            
            if(root->right != nullptr) {
                st.push(root->right);
            }
            
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        
        return preorder;
    }
};
