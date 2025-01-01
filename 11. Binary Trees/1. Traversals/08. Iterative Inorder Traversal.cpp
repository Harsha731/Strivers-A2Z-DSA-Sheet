/*
1. Traverse Left Subtree:
    Push the current node onto the stack.
    Move to the left child of the current node.

2. Process Node:
    When a node becomes NULL, pop a node from the stack.
    Add the node’s value to the result list.

3. Traverse Right Subtree: Move to the right child of the current node after processing the current node.
4. End Traversal: The loop ends when both the stack is empty and node is NULL, and the inorder traversal result is returned.
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
