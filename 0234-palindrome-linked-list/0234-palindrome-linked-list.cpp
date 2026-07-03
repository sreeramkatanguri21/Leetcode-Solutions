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
    bool solve(ListNode* head, ListNode* &temp) {
        if(head == NULL) {
            return true;
        }

        bool ans = solve(head->next, temp);

        if(!ans) return false;
        if(head->val == temp->val) {
            temp = temp->next;
            return true;
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        return solve(head, head);
    }
};