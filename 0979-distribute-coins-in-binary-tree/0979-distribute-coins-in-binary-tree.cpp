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
    int solve(TreeNode* root, int& ans) {
        if(!root) return 0;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        int val = root->val + left + right - 1; // val -> excess coins in current node(root)
        ans += abs(val);

        return val;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};