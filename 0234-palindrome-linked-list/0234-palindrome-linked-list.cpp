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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        
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
        ListNode* newHead = reverseList(slow);

        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        while(temp1) {
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
        //return solve(head, head);
    }
};