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
    void solve(TreeNode* root, int target, vector<int> curr, vector<vector<int>>& ans) {
        if(!root) return;
        
        curr.push_back(root->val);
        target -= root->val;
        if(!root->left && !root->right) {
            if(target == 0) ans.push_back(curr);
            return;
        }

        solve(root->left, target, curr, ans);
        solve(root->right, target, curr, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(root, targetSum, curr, ans);
        return ans;
    }
};