/*
QUESTION:-
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

/*  brute force APPROACH
1. Initialize a temp pointer to traverse the linked list.
2. Use a cnt variable to count the total nodes in the list by iterating until temp reaches NULL
3. Compute the position of the node to delete as L - N + 1.
4. Traverse the list using a new temp pointer until it points to the (L - N)-th node.
5. Adjust the link of the (L - N)-th node to skip the (L - N + 1)-th node.
6. Free the memory of the deleted node (if applicable).
Note: For languages with automatic garbage collection (e.g., Java, Python, JavaScript), explicit memory freeing isn't needed.
*/

/*
APPROACH:
To remove the nth node from the end of the linked list, we can follow these steps:
1. Initialize two pointers, `left` and `right`, to the head of the linked list.
2. Move the `right` pointer n nodes ahead.
3. If `right` becomes NULL, it means the first node needs to be removed. Return head->next.
4. Iterate until `right->next` becomes NULL.
5. Move both `left` and `right` pointers one node ahead in each iteration.
6. Once `right->next` becomes NULL, `left` will be pointing to the (n-1)th node from the end.
7. Update `left->next` to skip the nth node from the end.
8. Return the head of the modified linked list.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* left = head;
    ListNode* right = head;
    
    // Move the right pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        right = right->next;
    }
    
    // If right becomes NULL, remove the first node
    if (!right)
        return head->next;
    
    // Iterate until right->next becomes NULL
    while (right->next) {
        left = left->next;
        right = right->next;
    }
    
    // Update left->next to skip the nth node from the end
    left->next = left->next->next;
    
    return head;
}
