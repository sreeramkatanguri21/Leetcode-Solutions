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
    ListNode* solve(ListNode* head, int k, int n) {
        if(head == NULL) return head;
        if(n < k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=0; i<k; i++) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        head->next = solve(curr, k, n-k);

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLen(head);
        if(n < k) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i=0; i<k; i++) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        ListNode* newHead = prev;
        ListNode* tail = head;
        head = curr;
        n -= k;

        while(head) {
            if(n < k) {
                tail->next = head;
                break;
            }

            ListNode* curr = head;
            ListNode* prev = NULL;

            for(int i=0; i<k; i++) {
                ListNode* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }

            tail->next = prev;
            tail = head;
            head = curr;
            n -= k;
        }


        return newHead;




        // int n = getLen(head);
        // return solve(head, k, n);
    }
};