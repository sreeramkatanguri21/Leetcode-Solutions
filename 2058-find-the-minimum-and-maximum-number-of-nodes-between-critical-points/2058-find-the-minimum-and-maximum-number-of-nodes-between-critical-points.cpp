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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* forward = curr->next;
        int i = 1;
        int first = -1;
        int last = -1;
        int mini = INT_MAX;
        while(forward) {
            if((curr->val < forward->val && curr->val < prev->val) || (curr->val > forward->val && curr->val > prev->val)) {
                if(first != -1) mini = min(mini, i-last);
                if(first == -1) {
                    first = i;
                    last = i;
                }
                else {
                    last = i;
                }
            }

            prev = curr;
            curr = forward;
            forward = forward->next;
            i++;
        }

        if(first == last) return {-1, -1};

        return {mini, last-first};

    }
};