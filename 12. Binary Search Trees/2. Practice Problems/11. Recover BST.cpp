/*
Question:
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Time Complexity:
- The in-order traversal takes O(n) time, where n is the number of nodes in the BST.

Space Complexity:
- The space complexity is O(h), where h is the height of the BST, as the recursion stack stores the nodes in the leftmost path of the BST.

*/

/*
Using 4 pointers - prev, first, middle, last

1. Swapped nodes are not adjacent
3 25 7 8 10 15 20 5
Here, there are 2 violations for l > r
In the first violation, store the left (with the variable name as first) (right of first violation is called as middle)
In the second violation, store the right (with the variable name as last)
Now, swap the first and last

2. Swapped nodes are adjacent
If we have only 1 violation, then simply swap the 2 numbers (first and middle)
*/

class Solution {
private:
    TreeNode *first, *prev, *middle, *last;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;      // observe
            } else {
                last = root;        // observe
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;
        inorder(root);
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
__________________________________________

// We can remove the middle pointer by making last = root instead of middle = root

class Solution {
private:
    TreeNode *first, *prev, *last;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;   // unique to only for first time
            }
            last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = last = prev = nullptr;
        inorder(root);
        if (first && last) {
            swap(first->val, last->val);
        }
    }
};


