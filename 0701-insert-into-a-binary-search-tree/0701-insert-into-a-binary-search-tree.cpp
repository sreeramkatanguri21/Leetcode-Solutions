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
    TreeNode* solve(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }

        if(val < root->val) {
            root->left = solve(root->left, val);
        }
        else {
            root->right = solve(root->right, val);
        }

        return root;
    }
    void solve2(TreeNode* &root, int val) {
        if(!root) {
            root = new TreeNode(val);
            return;
        }

        if(val < root->val) {
            solve2(root->left, val);
        }
        else {
            solve2(root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        solve2(root, val);
        return root;
    }
};