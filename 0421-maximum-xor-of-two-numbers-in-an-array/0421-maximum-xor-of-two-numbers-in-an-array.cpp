class Node {
    public:
        Node* links[2];

    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};
class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;

            for(int i=31; i>=0; i--) {
                int bit = ((num >> i) & 1);
                if(!node->containsKey(bit)) {
                    node->put(bit, new Node());
                }

                node = node->get(bit);
            }
        }

        int getMax(int num) {
            Node* node = root;
            int ans = 0;

            for(int i=31; i>=0; i--) {
                int bit = ((num >> i) & 1);
                if(node->containsKey(1-bit)) {
                    ans = ans | (1 << i);
                    node = node->get(1-bit);
                }
                else {
                    node = node->get(bit);
                }
            }

            return ans;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto num: nums) {
            trie->insert(num);
        }

        int ans = 0;

        for(auto num: nums) {
            ans = max(ans, trie->getMax(num));
        }
        return ans;
    }
};