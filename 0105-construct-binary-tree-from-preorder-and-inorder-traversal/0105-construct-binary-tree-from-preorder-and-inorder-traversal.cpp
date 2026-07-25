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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inorderStart, int inorderEnd, int n, unordered_map<int, int>& mpp) {
        if(preIdx >= n) return NULL;
        if(inorderStart > inorderEnd) {
            return NULL;
        }

        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        int idx = mpp[val];

        root->left = solve(preorder, inorder, preIdx, inorderStart, idx-1, n, mpp);
        root->right = solve(preorder, inorder, preIdx, idx+1, inorderEnd, n, mpp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }

        int preIdx = 0;
        int inorderStart = 0;
        int inorderEnd = n-1;
        return solve(preorder, inorder, preIdx, inorderStart, inorderEnd, n, mpp);
    }
};