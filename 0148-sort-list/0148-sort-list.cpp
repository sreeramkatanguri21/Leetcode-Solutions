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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left && right) {
            if(left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if(left) temp->next = left;
        if(right) temp->next = right;

        return dummy->next;
    }
    ListNode* mergeSort(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                prev = slow;
                slow = slow->next;
            }
        }
        prev->next = NULL;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(slow);

        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};