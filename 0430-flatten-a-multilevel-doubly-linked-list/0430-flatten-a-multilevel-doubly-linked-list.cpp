/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    pair<Node*, Node*> solve(Node* head) {
        if(head == NULL) return {head, head};
        
        Node* temp = head;
        Node* tail = NULL;

        while(temp) {
            if(temp->child) {
                auto [childHead, childTail] = solve(temp->child);
                temp->child = NULL;
                Node* forward = temp->next;
                temp->next = childHead;
                childHead->prev = temp;
                childTail->next = forward;
                if(forward) forward->prev = childTail;
                
                tail = childTail;
                temp = forward;
            }
            else {
                tail = temp;
                temp = temp->next;
            }
        }

        return {head, tail};
    }
    Node* flatten(Node* head) {
        stack<Node*> s;

        Node* temp = head;

            while(temp) {
                if(temp->child) {
                    Node* forward = temp->next;
                    temp->next = temp->child;
                    temp->child = NULL;
                    temp->next->prev = temp;
                    if(forward) {
                        forward->prev = NULL;
                        s.push(forward);
                    }
                }
                if(temp->next == NULL && !s.empty()) {
                    auto top = s.top();
                    s.pop();
                    temp->next = top;
                    top->prev = temp;
                }
                temp = temp->next;
            }

        return head;




        // auto [h, t] = solve(head);
        // return h;
    }
};