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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postIdx, int inorderStart, int inorderEnd, int n, unordered_map<int, int>& mpp) {
        if(postIdx < 0) return NULL;
        if(inorderStart > inorderEnd) {
            return NULL;
        }

        int val = postorder[postIdx--];
        TreeNode* root = new TreeNode(val);
        int idx = mpp[val];

        root->right = solve(postorder, inorder, postIdx, idx+1, inorderEnd, n, mpp);
        root->left = solve(postorder, inorder, postIdx, inorderStart, idx-1, n, mpp);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }

        int postIdx = n-1;
        int inorderStart = 0;
        int inorderEnd = n-1;
        return solve(postorder, inorder, postIdx, inorderStart, inorderEnd, n, mpp);
    }
};
