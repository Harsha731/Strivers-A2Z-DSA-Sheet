/*
QUESTION:
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its 
corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in 
the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Brute Force APPROACH :

Step 1:Initialise variables ‘temp’ as a pointer to the head of the original linked list to traverse it. Create an empty unordered_map, to map original nodes to their corresponding copied nodes.

Step 2: Iterate through the original linked list and for each node in the linked list create a new node with the same data value as the original data. Map the original node to its copied node in the map.

Step 3: Iterate through the original list again but this time connect the pointers of the copied nodes in the same arrangement as the original node.
Get the copied node corresponding to the original node using the map.
Set the next pointer of the copied node to the copied node mapped to the original node’s next node.
Set the random pointer of the copied node to the original node’s next node copied from the map.

Step 4: Return the head of the deep copied list which is obtained by retrieving the copied nodes mapped to the original head from the map.

APPROACH:
1. Insert Copy Nodes in Between:
Traverse the original list.
For each node, create a copy node and insert it immediately after the original node.
This creates a linked structure: original -> copy -> original -> copy.

2. Connect Random Pointers:
Traverse the modified list.
Set the random pointer of each copy node to point to the corresponding copy of the random pointer of its original node.

3. Separate the Lists:
Traverse the list again to restore the original list.
Extract the deep copy list by detaching the copied nodes.

4. Return the Deep Copy:
Return the head of the copied list.

TIME COMPLEXITY:
The time complexity of this approach is O(n) since we traverse the original list once to create the copied list.

SPACE COMPLEXITY:
The space complexity is also O(n) because we create a new node for each node in the original list.

CODE:
*/
// TC : O(3N)
class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val); // Create a copy node
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            copyNode->random = temp->random ? temp->random->next : NULL; // Connect random pointer
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* copyHead = head->next;

        while (temp != nullptr) {
            Node* copyTemp = temp->next;
            temp->next = copyTemp->next; // Restore original list
            copyTemp->next = copyTemp->next ? copyTemp->next->next : NULL; // Separate copy list
            temp = temp->next;
        }

        return copyHead;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
