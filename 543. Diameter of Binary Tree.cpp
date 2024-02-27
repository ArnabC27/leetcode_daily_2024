/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        depthFirstSearch(root);
        return maxDiameter;
    }

private:
    int maxDiameter;

    int depthFirstSearch(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int leftHeight = depthFirstSearch(node->left);
        int rightHeight = depthFirstSearch(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);

    }
};
