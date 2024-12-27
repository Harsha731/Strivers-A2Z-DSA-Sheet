/*
QUESTION:-
A number N is represented in a linked list such that each digit corresponds to a node in the linked list. 
You need to add 1 to the number represented by the linked list.

APPROACH:
To add 1 to the number represented by the linked list, we can reverse the linked list, perform the addition, and then reverse it back.
First, reverse the linked list.
Traverse the reversed linked list while keeping track of the carry.
Add 1 to the least significant digit (head) and update the carry if necessary.
Continue traversing the linked list, adding the carry to each digit and updating the carry.
If there is still a remaining carry after traversing the linked list, create a new node with the carry as its value and append it to the end of the linked list.
Reverse the linked list again to restore its original order.

TIME COMPLEXITY: O(N), where N is the length of the linked list.
SPACE COMPLEXITY: O(1)

*/

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

Node* addOne(Node* head) {
    // Reverse the list to make addition easier
    head = reverseLL(head);
    
    Node* curr = head;
    int carry = 1;

    // Traverse the reversed list and add 1
    while (curr) {
        int sum = curr->data + carry;
        curr->data = sum % 10;   // Update the current node with the sum's unit digit
        carry = sum / 10;        // Update the carry for the next iteration

        // If no carry, we can stop early
        if (carry == 0) break;
        
        curr = curr->next; // Move to the next node
    }

    // If carry is still left, add a new node
    if (carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    // Reverse the list back to its original order
    head = reverseLL(head);

    return head;
}
