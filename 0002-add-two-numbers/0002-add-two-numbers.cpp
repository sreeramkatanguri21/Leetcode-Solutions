/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
        
    //     while(curr) {
    //         ListNode* forward = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = forward;
    //     }
        
    //     return prev;
    // }
    // void insertAtTail(int val, ListNode* &head, ListNode* &tail) {
    //     ListNode* newNode = new ListNode(val);

    //     if(head == NULL) {
    //         head = newNode;
    //         tail = newNode;
    //     }
    //     else {
    //         tail->next = newNode;
    //         tail = newNode;
    //     }
    // }
    void solve(ListNode* l1, ListNode* l2, int carry, ListNode* &head, ListNode* &tail) {
        if(!l1 && !l2 && carry == 0) return;

        int a = l1?l1->val:0;
        int b = l2?l2->val:0;

        int sum = a + b + carry;
        int digit = sum%10;
        carry = sum/10;

        tail->next = new ListNode(digit);
        tail = tail->next;

        l1 = l1?l1->next:l1;
        l2 = l2?l2->next:l2;

        solve(l1, l2, carry, head, tail);


    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        solve(l1, l2, 0, head, tail);

        return head->next;


        // ListNode* temp1 = l1;
        // ListNode* temp2 = l2;
        // int carry = 0;
        // ListNode* dummy = new ListNode(-1);
        // ListNode* temp = dummy;
        // while(temp1 || temp2 || carry != 0) {
        //     int a = temp1!=NULL?temp1->val:0;
        //     int b = temp2!=NULL?temp2->val:0;
            
        //     int sum = a + b + carry;
        //     int val = sum%10;
        //     ListNode* newNode = new ListNode(val);
        //     temp->next = newNode;
        //     temp = newNode;

        //     carry = sum/10;
        //     temp1 = (temp1!=NULL)?temp1->next:temp1;
        //     temp2 = (temp2!=NULL)?temp2->next:temp2;

        // }

        // return dummy->next;
    }
};