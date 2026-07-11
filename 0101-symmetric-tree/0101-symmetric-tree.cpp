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
    bool areMirror(TreeNode* a, TreeNode* b) {
        // Your code here
        if(!a && b) return false;
        if(a && !b) return false;
        if(!a && !b) return true;
        
        if(a->val != b->val) return false;
        
        bool op1 = areMirror(a->left, b->right);
        bool op2 = areMirror(a->right, b->left);
        
        return op1 && op2;
    }
    bool isSymmetric(TreeNode* root) {
        return areMirror(root->left, root->right);
    }
};