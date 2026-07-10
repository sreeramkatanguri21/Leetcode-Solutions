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
    int ans = INT_MIN;
    int solve(TreeNode* root) {
        if(!root) return 0;

        auto left = solve(root->left);
        auto right = solve(root->right);

        int val = max({root->val, root->val+left, root->val+right, root->val+left+right});
        ans = max(ans, val);

        return max({root->val, root->val+left, root->val+right});


    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};