/* 
1. Current Node is Not NULL:
    • Push the current node onto the stack.
    • Move to its left child to process the left subtree.

2. Current Node is NULL:
    • Peek at the top node in the stack to check its right child:
        • Right Child is NULL or Processed: Pop the node from the stack and add its value to the result. 
                Continue popping while the node is the right child of the next top node.  [already processed = backtracking]
        • Right Child Exists: Set the current node to the right child to process the right subtree.

3. Traversal Complete:
    • When the stack is empty and the current node is NULL, all nodes have been processed, and the postorder array contains the result.
*/

vector<int> postOrder(Node* root) {
    if (root == NULL)
        return {};

    Node* curr = root;
    stack<Node*> st;
    vector<int> postorder;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* temp = st.top()->right;

            if (temp == NULL) {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            } else {
                curr = temp;
            }
        }
    }
    return postorder;
}
