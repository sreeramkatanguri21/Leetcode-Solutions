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
    int getPathLen(TreeNode* root, int val) {
        if(!root) return 0;
        if(root->val != val) return 0;

        return 1 + max(getPathLen(root->left, val), getPathLen(root->right, val));
    }
    int solve(TreeNode* root) {
        if(!root) return 0;

        int val = getPathLen(root->left, root->val) + getPathLen(root->right, root->val);
        int left = solve(root->left);
        int right = solve(root->right);

        return max({val, left, right});

    }
    int longestUnivaluePath(TreeNode* root) {
        return solve(root);
    }
};