class Node {
    public:
        Node* links[26];
        bool isEnd;
        int idx;

        Node() {
            for(int i=0; i<26; i++) {
                links[i] = NULL;
            }
            isEnd = false;
            idx = -1;
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

        void insert(string word, int i) {
            Node* node = root;

            for(char ch: word) {
                if(!node->containsKey(ch)) {
                    node->put(ch, new Node());
                }

                node = node->get(ch);
            }

            node->setEnd();
            node->idx = i;
        }
        bool checkPalin(string& str, int i, int j) {
            while(i < j) {
                if(str[i] != str[j]) return false;
                i++;
                j--;
            }

            return true;
        }
        void helper(Node* node, string& str, vector<vector<int>>& ans, int curr) {
            if(curr == 3) cout << str << endl;
            if(node->isWordEnd()) {
                if(checkPalin(str, 0, str.length()-1)){
                    if(node->idx != curr)ans.push_back({node->idx, curr});
                }
            }
            for(int k=0; k<26; k++) {
                    if(node->links[k]) {
                        char ch = (char)(k+'a');
                        str.push_back(ch);
                        helper(node->get(ch), str, ans, curr);
                        str.pop_back();
                    }
                }
        }
        void solve(Node* node, string& word, int i, int curr, vector<vector<int>>& ans) {
            if(i < 0 && node->isWordEnd() && node->isLast()) {
                if(node->idx != curr) ans.push_back({node->idx, curr});
                return;
            }
            else if(i < 0 && !node->isLast()) {
                string str = "";
                helper(node, str, ans, curr);
                return;
            }
            else if(node->isLast()) {
                if(checkPalin(word, 0, i)) {
                    if(node->idx != curr) ans.push_back({node->idx, curr});
                }
                return;
            }
            else if(node->isWordEnd()) {
                if(checkPalin(word, 0, i)) {               
                    if(node->idx != curr) ans.push_back({node->idx, curr});
                }
            }

            if(node->containsKey(word[i])) {
                solve(node->get(word[i]), word, i-1, curr, ans);
            }

        }
        void findPalin(string& word, vector<vector<int>>& ans, int curr) {
            int j = word.size()-1;
            Node* node = root;
            solve(node, word, j, curr, ans);
        }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        int n = words.size();
        for(int i=0; i<n; i++) {
            trie->insert(words[i], i);
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            cout << i << endl;
            string word = words[i];
            trie->findPalin(word, ans, i);
        }

        return ans;
    }
};