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
        void printAllWords(Node* node, string& str, int& ans, unordered_map<string, int>& mpp) {
            if(node->isEnd) {
                ans += mpp[str];
            }

            for(int i=0; i<26; i++) {
                if(node->links[i]) {
                    str.push_back(i+'a');
                    printAllWords(node->links[i], str, ans, mpp);
                    //backtrack
                    str.pop_back();
                }
            }
        }
        int findAllWordsWithPrefix(string pre, unordered_map<string, int>& mpp) {
            Node* node = root;
            string str = "";
            for(auto& ch: pre) {
                if(!node->containsKey(ch)) return {};
                str.push_back(ch);
                node = node->get(ch);
            }

            int ans = 0;
            printAllWords(node, str, ans, mpp);
            return ans;
        }

};
class MapSum {
public:
    Trie* trie;
    unordered_map<string, int> mpp;
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        mpp[key] = val;
        trie->insert(key);
    }
    
    int sum(string prefix) {
        return trie->findAllWordsWithPrefix(prefix, mpp);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */