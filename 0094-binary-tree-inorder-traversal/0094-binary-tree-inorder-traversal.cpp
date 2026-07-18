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
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> ans;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }

        while(!st.empty()) {
            ans.push_back(st.top()->val);
            TreeNode* curr = st.top()->right;
            st.pop();

            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
        }

        return ans;

        // vector<int> ans;
        // inorder(root, ans);
        // return ans;
    }
};