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
    int power(int a, int b) {
        int res = 1;
        while(b) {
            if(b&1) res *= a;
            a *= a;
            b >>= 1;
        }

        return res;
    }
    pair<bool, int> solve(TreeNode* root, vector<int>& v) {
        if(!root) return {true, 0};

        auto left = solve(root->left, v);
        auto right = solve(root->right, v);

        bool isBalanced = false;
        if(left.first && right.first && left.second == right.second) {
            isBalanced = true;
            v.push_back(power(2, left.second+1)-1);
        }

        return {isBalanced, left.second+1};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> v;
        solve(root, v);

        sort(rbegin(v), rend(v));
        if(k > v.size()) return -1;
        return v[k-1];

    }
};