// Priority Queue: A priority queue is used to store the nodes in sorted order based on their values. It ensures that the smallest node is processed first.

// Push Heads to Priority Queue: The heads of all non-null lists are pushed into the priority queue, so that the smallest node is at the top.

// Dummy Node: A dummy node is created to simplify the merging process by serving as the starting point of the merged list.

// Process the Priority Queue:

// While the queue is not empty, the smallest node is popped and attached to the merged list.
// If the node has a next node, it is pushed into the priority queue.
// Return Merged List: After all nodes are processed, the merged list is returned, skipping the dummy node.

// Time Complexity:
// O(N * log(K)), where N is the total number of nodes and K is the number of lists.
// Space Complexity:
// O(K) due to the space used by the priority queue to store up to K nodes at a time.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue to store nodes in sorted order
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Push the head of each non-null list into the priority queue
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // Dummy node to simplify merging
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Process the priority queue
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            // If the node has a next node, push it to the priority queue
            if (node.second->next) {
                pq.push({node.second->next->val, node.second->next});
            }

            // Attach the current node to the merged list
            temp->next = node.second;
            temp = temp->next;
        }

        // Return the merged list (skipping the dummy node)
        return dummy->next;
    }
};
____________________

// mergeTwoLists Function: Recursively merges two sorted linked lists by comparing their heads and merging the rest.

// mergeKLists Function:

// Starts with the first list and merges it with the others one by one.
// Uses mergeTwoLists to combine two lists at a time.
// Recursive Logic: For each pair of lists, the smaller node is attached to the merged list, and recursion continues with the remaining nodes.

// Efficiency:

// Time Complexity: O(N * log(K)), where N is the total number of nodes and K is the number of lists.
// Space Complexity: O(log(K)) due to recursion stack.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases
        if (!list1) return list2;
        if (!list2) return list1;

        // Recursive merge logic
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Start with the first list
        ListNode* mergedList = lists[0];

        // Recursively merge each list into the current merged list
        for (int i = 1; i < lists.size(); i++) {
            mergedList = mergeTwoLists(mergedList, lists[i]);
        }

        return mergedList;
    }
};
