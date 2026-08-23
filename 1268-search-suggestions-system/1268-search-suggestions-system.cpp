class Node {
    public:
        Node* links[26];
        bool isTerminal;

        Node() {
            for(int i=0; i<26; i++) {
                links[i] = NULL;
            }
            isTerminal = false;
        }

        bool containsKey(char ch) {
            return links[ch-'a'] != NULL;
        }

        Node* get(char ch) {
            return links[ch-'a'];
        }

        void put(char ch, Node* node) {
            links[ch-'a'] = node;
        }

        void setEnd() {
            isTerminal = true;
        }

        bool isEnd() {
            return isTerminal;
        }

        bool isLast() {
            for(int i=0; i<26; i++) {
                if(links[i]) return false;
            }

            return true;
        }
};
class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node = root;

            for(auto ch: word) {
                if(!node->containsKey(ch)) {
                    node->put(ch, new Node());
                }

                node = node->get(ch);
            }

            node->setEnd();
        }
        void helper(Node* node, string str, vector<string>& curr) {
            if(node->isEnd()) {
                if(curr.size() < 3) curr.push_back(str);
            } 


            for(int i=0; i<26; i++) {
                char ch = 'a' + i;
                if(node->containsKey(ch)) {
                    helper(node->get(ch), str + ch, curr);
                }
            }
        }
        void solve(string& str, vector<string>& curr) {
            Node* node = root;

            for(auto ch: str) {
                if(!node->containsKey(ch)) return;
                node = node->get(ch);
            }

            helper(node, str, curr);
        }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for(auto& str: products) {
            trie->insert(str);
        }
        vector<vector<string>> ans;
        string str = "";
        for(auto &ch: searchWord) {
            vector<string> curr;
            str.push_back(ch);

            trie->solve(str, curr);
            ans.push_back(curr);
        }

        return ans;
    }
};