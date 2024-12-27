/*
QUESTION:-
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
*/

/*
Brute Force APPROACH :
Step 1:Traverse through the LL using the traversal technique of assigning a temp node to the head and iterating by moving to the next element till we reach null.

Step 2: While traversing, keep a track of the visited nodes in the map data structure.
Note: Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.

Step 3: If a previously visited node is encountered again, that proves that there is a loop in the linked list hence return that node.
Step 4: If the traversal is completed, and we reach the last point of the LL which is null, it means there was no loop, hence we return null.
*/

// APPROACH

/* 
1. Floyd's Cycle Detection (Tortoise and Hare):
Two pointers (slow and fast) are used to detect a cycle.
slow moves one step at a time, while fast moves two steps.
If there’s a cycle, slow and fast will eventually meet inside the cycle.

2. Cycle Detection:
If slow == fast, a cycle is detected.
Reset slow to the head and move both slow and fast one step at a time until they meet again. This node is the starting point of the cycle.

3. No Cycle:
If fast reaches NULL or fast->next is NULL, the list doesn’t contain a cycle, and the function returns NULL.

4. TC : O(N), where N is the number of nodes in the list. Both pointers traverse the list at most twice.
SC : O(1), as only two pointers are used and no extra space for data structures is required.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


