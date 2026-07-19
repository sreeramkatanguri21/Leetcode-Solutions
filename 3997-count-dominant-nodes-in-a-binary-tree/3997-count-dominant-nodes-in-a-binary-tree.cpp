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
    int solve(TreeNode* root, int& cnt) {
        if(!root) return INT_MIN;

        int left = solve(root->left, cnt);
        int right = solve(root->right, cnt);

        if(root->val >= left && root->val >= right) cnt++;

        return max({root->val, left, right});
    }
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};