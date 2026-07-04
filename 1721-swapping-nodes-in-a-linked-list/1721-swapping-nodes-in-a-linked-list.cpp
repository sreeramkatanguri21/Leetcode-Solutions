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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLen(head);
        ListNode* temp1 = NULL, *temp2 = NULL, *curr = head;

        if(k == n-k+1) return head;

        for(int i=1; i<=n; i++) {
            if(i == k) temp1 = curr;
            if(i == n-k+1) temp2 = curr;

            curr = curr->next;
        }

        swap(temp1->val, temp2->val);

        return head;
    }
};