/*
Question:
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values.
Your task is to find the In-Order, Pre-Order, and Post-Order traversals of the given binary tree.
*/
_______________________________________

/*
If the state is ‘1’ ie. preorder: store the node’s data in the preorder array and move its state to 2 (inorder) 
    for this node. Push this updated state back onto the stack and push its left child as well.
If the state is ‘2’ ie. inorder: store the node’s data is the inorder array and update its state to 3 (postorder) 
    for this node. Push the updated state back onto the stack and push the right child onto the stack as well.
If the state is ‘3’ ie. postorder: store the node’s data in the postorder array and pop it.

preOrder  :  Root, L, R    (first time)
postOrder :  L, Root, R    (when L->R)
inOrder   :  L, R, Root    (when leaving the subtree / parent node)

TC : O(3N) each node was visited thrice
SC : O(4N) one stack + 3 vectors for storage
*/

vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;
    if (root == NULL) {
        return {};
    }

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it);
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        } else {
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
________________________________________________________________
/*  [ Optimal ] with TC : O(N) 
Approach:
- We can perform the tree traversals recursively using three functions:
    - In-Order Traversal: Visit the left subtree, visit the current node, visit the right subtree.
    - Pre-Order Traversal: Visit the current node, visit the left subtree, visit the right subtree.
    - Post-Order Traversal: Visit the left subtree, visit the right subtree, visit the current node.
- For each traversal, we can maintain a vector to store the values of the visited nodes in the respective order.

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N) as we store the values of the nodes in vectors for each traversal.

Code:
*/

void traversal(BinaryTreeNode<int>* root, vector<int>& pre, vector<int>& ino, vector<int>& pos) {
    if (root == NULL) {
        return;
    }

    // Pre-Order Traversal
    pre.push_back(root->data);
    traversal(root->left, pre, ino, pos);
    // In-Order Traversal
    ino.push_back(root->data);
    traversal(root->right, pre, ino, pos);
    // Post-Order Traversal
    pos.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int>* root) {
    vector<vector<int>> ans;
    vector<int> pre;
    vector<int> ino;
    vector<int> pos;

    traversal(root, pre, ino, pos);

    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);

    return ans;
}
