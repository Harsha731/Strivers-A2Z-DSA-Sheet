/* QUESTION:

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the 
target is set on fire. It is known that in 1 second, all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Example 1:
Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10

Target Node = 8
Output: 7
Explanation: If the leaf with the value 8 is set on fire:
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


APPROACH:

To find the minimum time required to burn the complete binary tree, we need to perform a BFS (level-order traversal) starting 
from the target node. While doing BFS, we will also keep track of the parent node for each node using a hash map. 
The parent node will be used to traverse upward from the target node in the BFS process.

We will burn the target node and its adjacent nodes (left child, right child, and parent) one by one in each second. 
By the time we burn all nodes in the last level, all other nodes in the binary tree would have been burned as well.

Finally, we will count the number of seconds it took to burn the complete binary tree.

COMPLEXITY ANALYSIS:

Let `n` be the number of nodes in the binary tree.
- Time Complexity: The time complexity of this approach is O(n) since we perform a BFS starting from the target node, 
visiting all nodes in the binary tree once.
- Space Complexity: The space complexity is O(n) for the queue and the hash map.

CODE:
*/

*/
class Solution {
  public:
    void setParent(Node* root, unordered_map<Node*, Node*>& parent, Node*& start, int target) {
        if (!root) return;
        if (root->data == target) start = root;                   // Finding the root in the fly
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        setParent(root->left, parent, start, target);
        setParent(root->right, parent, start, target);
    }

    int minTime(Node* root, int target) {
        
        unordered_map<Node*, Node*> parent;
        Node* start = nullptr;
        setParent(root, parent, start, target);

        queue<Node*> q;
        unordered_set<Node*> visited;

        q.push(start);
        visited.insert(start);
        int time = 0;

        while (!q.empty()) {
            int n = q.size();
            bool burnt = false;

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                // Process left child
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                    burnt = true;
                }

                // Process right child
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                    burnt = true;
                }

                // Process parent
                if (parent[curr] && visited.find(parent[curr]) == visited.end()) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                    burnt = true;
                }
            }
            if (burnt) time++;
        }

        return time;
    }
};
