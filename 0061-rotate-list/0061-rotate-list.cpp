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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int n = getLen(head);
        k = k%n;
        if(k == 0) return head;

        ListNode* temp = head;
        for(int i=0; i<n-k-1; i++) {
            temp = temp->next;
        }

        ListNode* forward = temp->next;
        temp->next = NULL;
        temp = forward;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = head;

        return forward;
    }
};