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
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* solve(ListNode* head, int k) {
        if(head == NULL) return head;
        int n = getLen(head);
        if(n < k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=0; i<k; i++) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        head->next = solve(curr, k);

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};