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
    void preOrder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;

                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == curr) {
                    prev->right = NULL;
                    curr = curr->right;
                }
                else {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
            }
        }

        return ans;
        
        // stack<TreeNode*> st;
        // TreeNode* curr = root;
        // vector<int> ans;

        // while(curr || !st.empty()) {
        //     if(!curr) {
        //         curr = st.top();
        //         st.pop();
        //     }

        //     ans.push_back(curr->val);
        //     if(curr->right) st.push(curr->right);
        //     curr = curr->left;
        // }

        // return ans;



        // Approach-1 -> Using Recursion -> T.C -> O(n), S.C -> O(n) [auxilary recursive stack space]
        // vector<int> ans;
        // preOrder(root, ans);
        // return ans;
    }
};