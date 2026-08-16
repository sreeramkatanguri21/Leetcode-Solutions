#include <bits/stdc++.h>
using namespace std;
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
        
        string findSmallestPrefix(string str) {
            Node* node = root;
            string pref = "";

            for(auto& ch: str) {
                if(node->isEnd) return pref;
                if(!node->containsKey(ch)) {
                    return "";
                }

                pref.push_back(ch);
                node = node->get(ch);
            }

            return pref;
        }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();

        for(auto word: dictionary) {
            trie->insert(word);
        }

        string str = "";
        string ans = "";
        int n = sentence.length();
        for(int i=0; i<n; i++) {
            if(sentence[i] == ' ') {
                string pref = trie->findSmallestPrefix(str);
                if(pref != "") {
                    ans += pref;
                }
                else {
                    ans += str;
                }
                ans.push_back(' ');
                str = "";
            }
            else {
                str.push_back(sentence[i]);
            }
        }

        string pref = trie->findSmallestPrefix(str);
        if(pref != "") {
            ans += pref;
        }
        else {
            ans += str;
        }

        return ans;
    }
};