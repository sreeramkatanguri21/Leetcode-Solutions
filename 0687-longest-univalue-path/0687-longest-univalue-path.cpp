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
    int solve1(TreeNode* root) {
        if(!root) return 0;

        int val = getPathLen(root->left, root->val) + getPathLen(root->right, root->val);
        int left = solve1(root->left);
        int right = solve1(root->right);

        return max({val, left, right});

    }
    pair<int, int> solve(TreeNode* root) {
        if(!root) return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);
        int val = 0;
        int pathLen = 1;
        if(root->left && root->left->val == root->val) {
            val += left.second;
            pathLen = max(pathLen, 1+left.second);
        }
        if(root->right && root->right->val == root->val) {
            val += right.second;
            pathLen = max(pathLen, 1+right.second);
        }

        return {max({val, left.first, right.first}), pathLen};

    }
    int longestUnivaluePath(TreeNode* root) {
        auto ans = solve(root);
        return ans.first;
    }
};