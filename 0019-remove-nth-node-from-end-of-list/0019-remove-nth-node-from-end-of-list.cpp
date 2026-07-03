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
    int getLen(ListNode* head) {
        ListNode* temp = head;
        int len = 0;

        while(temp) {
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);
        // nth node from the end is same as (len-n+1)th node from the begin(start)
        int k = len-n+1;
        if(k == 1) return head->next;
        ListNode* temp = head;
        for(int i=0; i<k-2; i++) {
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next = NULL;
        delete toDelete;
        return head;
    }
};