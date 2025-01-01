/*
Question:
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Approach:

map<int, map<int, multiset<int>>> nodes stores nodes by vertical (x) and level (y).
queue<pair<Node*, pair<int, int>>> for BFS traversal.

Traversal:
Start BFS with root at (x = 0, y = 0).
For each node, store its value in nodes[x][y] and enqueue its left (x-1, y+1) and right (x+1, y+1) children.

Result Construction:
Traverse nodes to combine and sort values for each vertical column.

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N), where N is the number of nodes in the binary tree. This space is used to store the nodes in the unordered_map during the traversal.

Code:
*/

// NOTE:- we are keeping track of levels because of the question condition but if no such condition exists, then no need of level only hd will work.

class Solution {
public:
    vector<vector<int>> findVertical(Node* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            Node* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(temp->data);

            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
