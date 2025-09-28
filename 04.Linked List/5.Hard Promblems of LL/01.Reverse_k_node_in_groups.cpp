/*
QUESTION:-
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

APPROACH:
The idea is to reverse the nodes of the linked list in groups of size k.
First, we need to check if there are at least k nodes remaining in the linked list. If not, we return the head as it is.
Next, we reverse the first k nodes of the linked list. To do this, we maintain three pointers: prev, curr, and frwd.
We iterate through the first k nodes and at each step, we reverse the links between the nodes.
After reversing the first k nodes, prev becomes the new head, and curr becomes the new tail of the reversed group.
We recursively call the function on the remaining linked list starting from frwd (which points to the (k+1)-th node).
Finally, we update the next pointer of the original head to point to the reversed group obtained from the recursive call.


** Follow this approach
Everytime we are checking we are having atleast k nodes or not. 
If not there, then directly return head
Now reverse every k nodes and attach the (head of next k nodes) to the (last of this k nodes)


TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1).

*/


// __________________________________________

// The curr is at starting of next group each time

Node* reverseKGroupIterative(Node* head, int k) {
    if (!head || k <= 1) return head;

    // Dummy node before head to simplify connections
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node* prevGroupEnd = dummy;
    Node* curr = head;

    while (true) {
        Node* groupStart = curr;
        int count = 0;

        // Check if there are at least k nodes left
        Node* temp = curr;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) break; // not enough nodes to reverse

        // Reverse k nodes
        Node* prev = nullptr;
        Node* next = nullptr;
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect previous group with reversed group
        prevGroupEnd->next = prev;
        groupStart->next = curr;
        prevGroupEnd = groupStart;
    }

    return dummy->next;
}
// _______________________________________

// The curr is at starting of next group each time

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* ptr = head;
    for (int i = 0; i < k; i++) {
        if (!ptr)
            return head; // Return head if there are less than k nodes remaining
        ptr = ptr->next;
    }
    int count = k;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* frwd = NULL;
    while (count && curr) {
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
        count--;
    }
    if (frwd)
        head->next = reverseKGroup(frwd, k); // Recursive call for the remaining linked list
    return prev; // Return the new head of the reversed group
}t        
