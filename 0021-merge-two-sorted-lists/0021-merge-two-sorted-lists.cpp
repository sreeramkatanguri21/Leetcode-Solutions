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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                ListNode* forward = list1->next;
                list1->next = NULL;
                tail->next = list1;
                tail = list1;
                list1 = forward;
            }
            else {
                ListNode* forward = list2->next;
                list2->next = NULL;
                tail->next = list2;
                tail = list2;
                list2 = forward;
            }
        }

        if(list1) tail->next = list1;
        else tail->next = list2;
        
        return head->next;
    }
};