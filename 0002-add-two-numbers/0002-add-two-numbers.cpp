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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(temp1 || temp2 || carry != 0) {
            int a = temp1!=NULL?temp1->val:0;
            int b = temp2!=NULL?temp2->val:0;
            
            int sum = a + b + carry;
            int val = sum%10;
            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = newNode;

            carry = sum/10;
            temp1 = (temp1!=NULL)?temp1->next:temp1;
            temp2 = (temp2!=NULL)?temp2->next:temp2;

        }

        return dummy->next;
    }
};