class Node {
    public:
        Node* links[26];
        bool isEnd;

        Node() {
            for(int i=0; i<26; i++) {
                links[i] = NULL;
            }
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

        bool isWordEnd() {
            return isEnd;
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

            for(char ch: word) {
                if(!node->containsKey(ch)) {
                    node->put(ch, new Node());
                }

                node = node->get(ch);
            }

            node->setEnd();
        }
        bool solve(Node* node, string& word, int i) {
            if(i == word.size()) {
                return node->isWordEnd();
            }
            char ch = word[i];

            if(ch == '.') {
                bool ans = false;
                for(char c='a'; c<='z'; c++) {
                    if(node->containsKey(c)) {
                        ans = ans || solve(node->get(c), word, i+1);
                    }
                }
                return ans;
            }
            else {
                if(node->containsKey(ch)) {
                    return solve(node->get(ch), word, i+1);
                }
                else return false;
            }
        }
        bool search(string& word) {
            Node* node = root;
            return solve(node, word, 0);
        }
};
class WordDictionary {
public:
    Trie* trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */