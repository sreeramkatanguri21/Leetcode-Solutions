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
};
class MagicDictionary {
public:
    Trie* trie;
    MagicDictionary() {
        trie = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& word: dictionary) {
            trie->insert(word);
        }
    }
    bool solve(Node* node, string& word, int i, bool hasCharChanged) {
        if(i >= word.size() && node->isEnd()) {
            return hasCharChanged;
        }
        else if(i >= word.size() && !node->isEnd()) {
            return false;
        }

        bool ans = false;
        if(!hasCharChanged) {
            for(int k=0; k<26; k++) {
                if(node->links[k]) {
                    ans = ans || solve(node->links[k], word, i+1, (k+'a') != word[i]);
                }
            }
        }
        else {
            if(node->containsKey(word[i])) {
                ans = solve(node->get(word[i]), word, i+1, hasCharChanged);
            }
            else {
                ans = false;
            }
        }

        return ans;
    }
    bool search(string searchWord) {
        return solve(trie->root, searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */