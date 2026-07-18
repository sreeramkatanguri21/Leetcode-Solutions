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
    void postOrder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        vector<int> ans;
        auto curr = root;

        while(curr || !st.empty()) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                auto temp = st.top()->right;
                if(!temp) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while(!st.empty() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }

        return ans;




        // vector<int> ans;
        // stack<TreeNode*> st1, st2;
        // st1.push(root);

        // while(!st1.empty()) {
        //     auto curr = st1.top();
        //     st1.pop();
        //     st2.push(curr);

        //     if(curr->left) st1.push(curr->left);
        //     if(curr->right) st1.push(curr->right);
        // }

        // while(!st2.empty()) {
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }

        // return ans;

        // vector<int> ans;
        // postOrder(root, ans);
        // return ans;
    }
};