/*
QUESTION:-
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]
*/

/*
APPROACH:
To reverse a singly linked list, we can use an iterative approach.
Initialize three pointers: prev as NULL, curr as head, and frwd as NULL.
Iterate through the linked list until curr becomes NULL:
    - Store the next node of curr in frwd.
    - Set the next of curr to prev, reversing the link.
    - Move prev and curr one step forward.
    - Move curr to the next node (frwd) to continue the iteration.
Return prev, which will be the new head of the reversed list.
*/

// CODE:-

// Brute force approach

// Brute force approach :
// Step 1: Create an empty stack. This stack will be used to temporarily store the nodes from the original linked list as we traverse it.
// Step 2: Traverse the linked list using a temporary variable `temp` till it reaches null. At each node, push the value at the current node onto the stack. 
// Step 3: Set variable `temp` back to the head of the linked list. While the stack is not empty, set the value at the temp node to the value at the top of the stack. Pop the stack and move temp to the next node till it reaches null.
// Step 4: Return the head as the new head of the reversed linked list

// Method 1 : Iterative

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

// Method 2 : Recursive

Node* reverseLinkedList(Node* head) {
    // Base case: Empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Reverse the rest of the list
    Node* newHead = reverseLinkedList(head->next);

    // Adjust the pointers
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
