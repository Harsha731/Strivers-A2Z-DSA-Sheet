/**QUESTION:**

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is the head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

Brute Force APPROACH :

Step 1:Initialise an empty array to store the data extracted during the traversal.

Step 2: Start traversing through the top-level ‘next’ pointers of the linked list and for each node accessed by the ‘next’ pointer, traverse its ‘child’ nodes.
Iterate all the nodes until reaching the end of the child pointer list appending each node’s value to the array. Move to the next primary node and repeat the process of traversing the child nodes.

Step 3: Sort the array to arrange its collected node data in ascending order.

Step 4: Create a new linked list from the sorted array and return the flattened linked list

**APPROACH:**

Base Case:
If the head is null, indicating the end of the list, it is already flattened or there are no further nodes. Return the head as it is.
Similarly, if there's no next node, meaning there's only one node left in the list, return the head as it is since it's already flattened.

Step 1: Establish Base Case Conditions Check if the base case conditions are met, return the head if it is null or has no next pointer to head as there’s no further flattening or merging required.

Step 2: Recursively Merge the List:

Initiate the recursive flattening process by calling `flattenLinkedList` on the next node (`head -> next`).
The result of this recursive call is the head of the flattened and merged linked list.
Step 3: Merge Operations:

Inside the recursive call, call the merge function which takes care of the merging of these two lists based on their data values.
Read more about merging two linked lists here.
The merged list is updated in the head, which is then returned as the result of the flattening process.

**TIME COMPLEXITY:** The time complexity is O(N), where N is the total number of nodes in the linked list.

**SPACE COMPLEXITY:** The space complexity is O(1) since we are modifying the given linked list in-place without using any extra space.

**CODE:**/

Node* merge(Node* head1, Node* head2)  
{  
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data) {
        head1->bottom = merge(head1->bottom, head2);
        return head1;
    }
    else {
        head2->bottom = merge(head1, head2->bottom);
        return head2;
    }
}

Node* flatten(Node* root)
{
    if (root == NULL)
        return root;

    Node* left = root;
    Node* right = flatten(root->next);
    root->next = NULL;
    left = merge(left, right);
    return left;
}
