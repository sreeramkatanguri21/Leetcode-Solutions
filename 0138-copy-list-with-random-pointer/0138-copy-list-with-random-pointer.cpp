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
        if(head == NULL) return head;
        Node* temp = head;

        while(temp) {
            Node* forward = temp->next;
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = forward;
            temp = forward;
        }

        temp = head;
        while(temp) {
            temp->next->random = temp->random?temp->random->next: NULL;
            temp = temp->next->next;
        }

        Node* oldList = head;
        Node* newHead = head->next;
        Node* newList = head->next;

        while(newList && newList->next) {
            oldList->next = oldList->next->next;
            newList->next = newList->next->next;
            oldList = oldList->next;
            newList = newList->next;
        }
        oldList->next = NULL;

        return newHead;

        // unordered_map<Node*, Node*> mpp;
        // mpp[NULL] = NULL;
        // return solve(head, mpp);
    }
};