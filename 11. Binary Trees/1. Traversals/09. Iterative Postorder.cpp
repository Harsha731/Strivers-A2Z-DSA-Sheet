/*
1. Two Stacks for Postorder: Use two stacks:
    st1 for storing nodes during the traversal.
    st2 for reversing the node processing order to get postorder.

2. Push Root to st1: Push the root node onto st1 to start the traversal.

3. Iterative Traversal:
    While st1 is not empty, pop the top node and push it onto st2.
    Push the left child to st1 (if it exists).
    Push the right child to st1 (if it exists).

4. Postorder Result: After the traversal, st2 will have nodes in reverse postorder. Pop from st2 and add values to the postorder vector.
5. Return Result: Return the postorder vector containing the postorder traversal.
*/

vector<int> postOrder(Node* root) {
    vector<int> postorder;

    if(root == NULL){
        return postorder;
    }

    stack<Node*> st1, st2;

    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();

        st2.push(root);

        if(root->left != NULL){
            st1.push(root->left);
        }

        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}

