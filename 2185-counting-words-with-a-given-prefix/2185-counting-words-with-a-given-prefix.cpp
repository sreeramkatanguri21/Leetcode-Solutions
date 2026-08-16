class Node {
    public:
        Node* links[26];
        bool isEnd;

        Node() {
            for(int i=0; i<26; i++) links[i] = NULL;
            isEnd = false; 
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
            isEnd = true;
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

            for(auto &ch: word) {
                if(!node->containsKey(ch)) {
                    node->put(ch, new Node());
                }

                node = node->get(ch);
            }

            node->setEnd();
        }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int cnt = 0;
        
        for(auto& word: words) {
            bool match = true;
            for(int i=0; i<n; i++) {
                if(word[i] != pref[i]) {
                    match = false;
                    break;
                }
            }
            if(match) cnt++;
        }

        return cnt;
    }
};