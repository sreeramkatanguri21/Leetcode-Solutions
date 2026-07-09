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
    pair<int, int> solve2(TreeNode* root) {
        if(!root) return {0, 0};

        auto left = solve2(root->left);
        auto right = solve2(root->right);
        int val = abs(left.second-right.second);

        return {val + left.first + right.first, root->val+left.second+right.second};
    }
    int findTilt(TreeNode* root) {
        auto ans = solve2(root);
        return ans.first;
    }
};