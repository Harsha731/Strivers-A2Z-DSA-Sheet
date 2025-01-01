/**
 QUESTION:
 Given the root of a binary tree, check whether it is a mirror of itself
 (i.e., symmetric around its center).
 
 Example:
 Input: root = [1,2,2,3,4,4,3]
 Output: true
 */

/**
 APPROACH:
Helper Function: isSymmetricUtil compares two subtrees recursively by checking:
If both nodes are NULL.
If the nodes' values are equal.
If the left child of the first subtree and the right child of the second subtree are symmetric, and vice versa.
Base Case: The tree is symmetric if its left and right subtrees are mirrors of each other.

 COMPLEXITY ANALYSIS:
 - The time complexity is O(N), where N is the number of nodes in the binary tree, as we need to visit all the nodes once.
 - The space complexity is O(H), where H is the height of the tree, due to the recursive function calls on the stack.
   In the worst case, the height of the tree can be equal to the number of nodes, resulting in O(N) space complexity.

CODE:-
*/

class Solution {
private:
    bool isSymmetricUtil(Node* root1, Node* root2) {
        if (root1 == NULL || root2 == NULL) {
            return root1 == root2;
        }
        return (root1->data == root2->data)
            && isSymmetricUtil(root1->left, root2->right)
            && isSymmetricUtil(root1->right, root2->left);
    }

public:
    bool isSymmetric(Node* root) {
        if (!root) {
            return true;
        }
        return isSymmetricUtil(root->left, root->right);
    }
};

