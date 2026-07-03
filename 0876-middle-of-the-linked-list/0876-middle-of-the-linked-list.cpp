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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;


        // int n = getLen(head);
        // ListNode* temp = head;
        // for(int i=0; i<n/2; i++) {
        //     temp = temp->next;
        // }

        // return temp;
    }
};