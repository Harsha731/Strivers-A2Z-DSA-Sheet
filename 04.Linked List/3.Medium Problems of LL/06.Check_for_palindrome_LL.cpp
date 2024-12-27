/*
QUESTION:-
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/

/* 
Brute force approach:
Step 1: Create an empty stack. This stack will be used to temporarily store the nodes from the original linked list as we traverse it.
Step 2: Traverse the linked list using a temporary variable `temp` till it reaches null. At each node, push the value at the current node onto the stack. 
Step 3: Set variable `temp` back to the head of the linked list. While the stack is not empty, compare the value at the temp node to the value at the top of the stack. Pop the stack and move the temp to the next node till it reaches the end.
During the comparison, if at any point the values do not match, the linked list is not a palindrome and hence returns false.
Step 4: If all values match till emp reaches the end, it means that the linked list is a palindrome, as the values read the same way both forward and backward hence we return true.
*/

/*
APPROACH:
To determine if a linked list is a palindrome, we can follow these steps:
1. Find the middle node of the linked list using the slow and fast pointer technique.
2. Reverse the second half of the linked list.
3. Compare the first half of the original linked list with the reversed second half.
4. If all nodes match, the linked list is a palindrome.
5. If any node does not match, the linked list is not a palindrome.
*/

ListNode* reverseLL(ListNode* start) {
    ListNode* prev = NULL;
    ListNode* curr = start;
    while (curr) {
        ListNode* frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Find the middle node using the slow and fast pointer technique
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the linked list
    ListNode* reversedHalf = reverseLL(slow);
    
    // Compare the first half with the reversed second half
    while (reversedHalf) {
        if (head->val != reversedHalf->val)
            return false;
        head = head->next;
        reversedHalf = reversedHalf->next;
    }
    
    return true;
}

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)


