/*
QUESTION:-
Given the head of a linked list, rotate the list to the right by k places.

APPROACH:
To rotate the linked list to the right by k places, we need to perform the following steps:
1. Find the length of the linked list and connect the last node to the head to form a circular linked list.
2. Calculate the actual number of rotations by taking the modulus of k with the length of the linked list.
3. Traverse to the (length - k - 1)th node, which will be the new tail of the rotated list.
4. Set the new head as the next node of the (length - k - 1)th node and disconnect it from the rest of the list.
5. Return the new head.


**  Follow this
1-2-3-4-5-6-7-8-9-10 	k=3	    8-9-10-1-2-3-4-5-6-7
We want curr = 7, newHead = 8, so we traverse curr = 1 to curr = 7 (N-L-1 times or 6 times)
7->next = null. We go the end of the right half and make 10->next = head

TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1).

*/

int find_len(ListNode* head) {
    ListNode* curr = head;
    int cnt = 0;
    while (curr) {
        cnt++;
        if (curr->next == NULL) break; // Stop at the last node
        curr = curr->next;
    }
    return cnt;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head; // Handle edge cases

    int len = find_len(head);
    k = k % len; 
    if (k == 0) return head; 

    ListNode* curr = head;
    for (int i = 0; i < len - k - 1; i++) {
        curr = curr->next; // Traverse to the (len - k - 1)th node
    }

    ListNode* newHead = curr->next; 
    curr->next = NULL; 

    ListNode* temp = newHead;
    while (temp->next) {
        temp = temp->next; // Traverse to the end of the rotated part
    }
    temp->next = head; // Connect the end of the rotated part to the old head

    return newHead;
}
