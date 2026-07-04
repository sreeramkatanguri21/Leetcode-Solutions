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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp = head;
        int n = getLen(head);
        int cnt = n/k;
        int rem = n%k;

        for(int i=0; i<k; i++) {
            ListNode* head = new ListNode(-1);
            ListNode* tail = head;

            for(int j=0; j<cnt+(i<rem); j++) {
                ListNode* forward = temp->next;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
                temp = forward;
            }

            ans.push_back(head->next);

        }

        return ans;
    }
};