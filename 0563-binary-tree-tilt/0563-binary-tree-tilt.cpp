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
    int sum(TreeNode* root) {
        if(!root) return 0;

        return root->val + sum(root->left) + sum(root->right);
    }
    int solve(TreeNode* root) {
        if(!root) return 0;

        int val = abs(sum(root->left)-sum(root->right));
        int left = solve(root->left);
        int right = solve(root->right);

        return val + left + right;
    }
    int findTilt(TreeNode* root) {
        return solve(root);
    }
};