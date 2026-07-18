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
        queue<TreeNode*> q;
        q.push(root);

        string str = "";
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            if(!str.empty()) str.push_back(',');
            if(temp) {
                str += to_string(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            else {
                str.push_back('N');
            }
        }


        return str;
    }
    string decode(string data, int& i) {
        string curr = "";
        while(i < data.length() && data[i] != ',') {
            curr.push_back(data[i++]);
        }
        i++;

        return curr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() < 3) return NULL;
        
        queue<TreeNode*> q;
        int i = 0;
        string curr = decode(data, i);

        int val = stoi(curr);
        TreeNode* root = new TreeNode(val);
        q.push(root);

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            string curr = decode(data, i);

            if(curr != "N") {
                int val = stoi(curr);
                TreeNode* left = new TreeNode(val);
                temp->left = left;
                q.push(left);
            }

            curr = decode(data, i);

            if(curr != "N") {
                int val = stoi(curr);
                TreeNode* right = new TreeNode(val);
                temp->right = right;
                q.push(right);
            }
        }

        return root;
    }


    // // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
    //     if(!root) return "N";

    //     return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    // }

    // TreeNode* solve(string& data, int& i) {
    //     if(i >= data.length()) return NULL;

    //     string curr = "";
    //     while(i < data.length() && data[i] != ',') {
    //         curr.push_back(data[i++]);
    //     }
    //     i++;

    //     if(curr == "N") return NULL;
        
    //     int val = stoi(curr);
    //     TreeNode* root = new TreeNode(val);
    //     root->left = solve(data, i);
    //     root->right = solve(data, i);

    //     return root;
    // }
    // // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {
    //     int i = 0;
    //     return solve(data, i);
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));