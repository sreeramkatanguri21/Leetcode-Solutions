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
    int cnt = 0;
    int solve(TreeNode* root) {
        if(!root) return 1;

        int left = solve(root->left);
        int right = solve(root->right);

        if(left == 0 || right == 0) {
            cnt++;
            return 2;
        }
        else if(left == 2 || right == 2) {
            return 1;
        }
        else return 0;
    }
    int minCameraCover(TreeNode* root) {
        int rootState = solve(root);
        if(rootState == 0) {
            cnt++;
        }


        return cnt;
    }
};