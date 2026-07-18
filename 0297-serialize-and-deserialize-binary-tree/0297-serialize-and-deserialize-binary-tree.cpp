/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* solve(string& data, int& i) {
        if(i >= data.length()) return NULL;

        string curr = "";
        while(i < data.length() && data[i] != ',') {
            curr.push_back(data[i++]);
        }
        i++;
        
        if(curr == "N") return NULL;
        
        int val = stoi(curr);
        TreeNode* root = new TreeNode(val);
        root->left = solve(data, i);
        root->right = solve(data, i);

        return root;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return solve(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));