/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        
        while(temp) {
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = getLen(headA);
        int n2 = getLen(headB);
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if(n1 > n2) {
            for(int i=0; i<n1-n2; i++) {
                temp1 = temp1->next;
            }
        }
        else {
            for(int i=0; i<n2-n1; i++) {
                temp2 = temp2->next;
            }
        }

        while(temp1 && temp2) {
            if(temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};