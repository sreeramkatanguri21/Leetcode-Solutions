/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(Node* head, unordered_map<Node*, Node*>& mpp) {
        if(head == NULL) return NULL;

        Node* newHead = new Node(head->val);
        mpp[head] = newHead;
        newHead->next = solve(head->next, mpp);

        newHead->random = mpp[head->random];
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;
        mpp[NULL] = NULL;
        return solve(head, mpp);
    }
};