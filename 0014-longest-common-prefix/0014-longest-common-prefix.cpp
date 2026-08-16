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

        string findLongestPrefix() {
            Node* node = root;
            string ans = "";

            while(1) {
                if(node->isEnd) break;
                int cnt = 0;
                int child = -1;
                for(int i=0; i<26; i++) {
                    if(node->links[i]) {
                        child = i;
                        cnt++;
                    }
                }
                if(cnt > 1) break;
                ans.push_back(child+'a');
                node = node->get(child+'a');
            }

            return ans;
        }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();

        for(auto word: strs) trie->insert(word);


        return trie->findLongestPrefix();
    }
};