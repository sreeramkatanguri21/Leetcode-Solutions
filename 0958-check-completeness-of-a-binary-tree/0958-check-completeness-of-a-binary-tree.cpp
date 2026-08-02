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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        int idx = 1;
        while(!q.empty()) {
            auto [node, i] = q.front();
            q.pop();

            if(i != idx) return false;
            idx++;

            if(node->left) q.push({node->left, 2*i});
            if(node->right) q.push({node->right, 2*i+1});
        }

        return true;

    }
};