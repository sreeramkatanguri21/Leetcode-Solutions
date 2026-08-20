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

        Node* getRoot() {
            return root;
        }
};
class Solution {
public:
    map<pair<Node*, int>, int> dp;
    bool solve(Node* node, string& s, int i, Trie* trie) {
        if(i >= s.length()) {
            return node->isEnd();
        }

        if(dp.count({node, i})) return dp[{node, i}];

        bool ans = false;
        if(node->isEnd()) {
            ans = ans || solve(trie->getRoot(), s, i, trie);
        }

        if(node->containsKey(s[i])) {
            ans = ans || solve(node->get(s[i]), s, i+1, trie);
        }
        
        return dp[{node, i}] = ans;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for(auto word: wordDict) {
            trie->insert(word);
        }

        return solve(trie->root, s, 0, trie);
    }
};