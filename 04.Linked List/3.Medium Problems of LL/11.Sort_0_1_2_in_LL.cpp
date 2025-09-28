/*
QUESTION:-
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s in the linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Example:
Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

APPROACH:
Count the number of 0s, 1s, and 2s in the linked list.
Traverse the linked list and overwrite the nodes with 0s, 1s, and 2s based on their counts.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

*/

Node* segregate(Node* head) {
    int zeroCnt = 0, oneCnt = 0, twoCnt = 0;
    Node* curr = head;
    
    // Count the number of 0s, 1s, and 2s in the linked list
    while (curr) {
        if (curr->data == 0) zeroCnt++;
        if (curr->data == 1) oneCnt++;
        if (curr->data == 2) twoCnt++;
        curr = curr->next;
    }
    
    curr = head;
    
    // Overwrite the nodes with 0s, 1s, and 2s based on their counts
    while (zeroCnt) {
        curr->data = 0;
        zeroCnt--;
        curr = curr->next;
    }
    while (oneCnt) {
        curr->data = 1;
        oneCnt--;
        curr = curr->next;
    }
    while (twoCnt) {
        curr->data = 2;
        twoCnt--;
        curr = curr->next;
    }
    
    return head;
}
________________________________________________________________

// 1. Initialize Dummy Nodes: Create dummy nodes (zeroHead, oneHead, twoHead) to store the 0, 1, and 2 lists.
// 2. Traverse the Original List: Use the temp pointer to traverse the original list and append nodes to the corresponding list (0, 1, or 2).
// 3. Connect the Lists: After segregation, connect the 0 list to the 1 list, and the 1 list to the 2 list. Set the end of the 2 list to NULL.
// 4. Return Sorted List: Set the head to zeroHead->next and return the sorted linked list.
    
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head; // No sorting needed for empty or single-node list

        // Dummy nodes for 0s, 1s, and 2s
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        // Pointers to build the three lists
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        // Use temp to traverse the original list
        Node* temp = head;
        while (temp) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } else {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next; // Move to the next node
        }

        // Here, zero, one, two pointers are never null as they are actally dumym nodes created for this error not to arise
        // Connect the three lists
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = NULL; // Terminate the list

        // Update head to the start of the sorted list
        head = zeroHead->next;

        // Free dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};
