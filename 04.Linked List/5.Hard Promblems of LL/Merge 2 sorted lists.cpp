// Dummy Node: A dummy node is used to simplify handling the merged list’s head.
// Traversal: Compare the current nodes of both lists, attach the smaller node to the merged list, and move the respective pointer forward.
// Attach Remaining: Once one list is exhausted, attach the remaining nodes from the other list.
// Return: Return the merged list starting from the dummy node’s next pointer.
// Time Complexity: O(n + m)
// Space Complexity: O(1)

// Iteration

// Node<int>* means a pointer to a Node object that holds an int (integer) type value.

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2) {
    Node<int>* t1 = list1;
    Node<int>* t2 = list2;

    // Create a dummy node to simplify the logic
    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* temp = dummyNode;

    // Merge the two lists
    while (t1 != NULL && t2 != NULL) {
        if (t1->data < t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    // Attach the remaining part of the non-empty list
    if (t1) temp->next = t1;
    else temp->next = t2;

    // Return the merged sorted list, skipping the dummy node
    Node<int>* sortedList = dummyNode->next;
    delete dummyNode; // Free the dummy node
    return sortedList;
}
_________________________________

// Recursion

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2) {
    // Base cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Recursive merge
    if (list1->data < list2->data) {
        list1->next = sortTwoLists(list1->next, list2); // Attach smaller node and move list1
        return list1;
    } else {
        list2->next = sortTwoLists(list1, list2->next); // Attach smaller node and move list2
        return list2;
    }
}
