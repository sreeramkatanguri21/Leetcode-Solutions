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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prev = head;

        while(temp) {
            int sum = 0;
            while(temp->val != 0) {
                sum += temp->val;
                prev->next = temp->next;
                temp = prev->next;
            }

            temp->val = sum;
            prev = temp;
            temp = temp->next;
        }

        return head->next;


        // ListNode* temp = head->next;
        // ListNode* dummyHead = new ListNode(-1);
        // ListNode* dummyTail = dummyHead;

        // while(temp) {
        //     int sum = 0;
        //     while(temp->val != 0) {
        //         sum += temp->val;
        //         temp = temp->next;
        //     }

        //     dummyTail->next = new ListNode(sum);
        //     dummyTail = dummyTail->next;
        //     temp = temp->next;
        // }

        // return dummyHead->next;
    }
};