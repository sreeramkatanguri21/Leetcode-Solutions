class Node {
    public:
        Node* links[26];
        int prefixScore;
        bool isEnd;

        Node() {
            for(int i=0; i<26; i++) links[i] = NULL;
            prefixScore = 0;
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
        void addScore(int score) {
            prefixScore += score;
        }
};
class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(string word, int score) {
            Node* node = root;

            for(auto &ch: word) {
                if(!node->containsKey(ch)) {
                    node->put(ch, new Node());
                }

                node = node->get(ch);
                node->addScore(score);
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

        int findScore(string prefix) {
            Node* node = root;

            for(auto& ch: prefix) {
                if(!node->containsKey(ch)) {
                    return 0;
                }

                node = node->get(ch);
            }

            return node->prefixScore;
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
        if(mpp.count(key)) {
            int diff = val - mpp[key];
            mpp[key] = val;
            val = diff;
        }
        else mpp[key] = val;
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->findScore(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */