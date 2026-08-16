class Node {
    public: 
        string val;
        Node* prev;
        Node* next;

        Node(string val) {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
};
class BrowserHistory {
public:
    Node* head;
    Node* curr;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {
        Node* forward = curr->next;
        if(forward) {
            forward->prev = NULL;
            curr->next = NULL;
        }

        Node* newNode = new Node(url);
        newNode->prev = curr;
        curr->next = newNode;
        curr = newNode;
    }
    
    string back(int steps) {
        
        while(curr->prev && steps > 0) {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {

        while(curr->next && steps > 0) {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */