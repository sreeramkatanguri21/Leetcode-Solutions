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
    int solve(ListNode* head) {
        if(head == NULL) return 0;

        int carry = solve(head->next);
        int sum = 2*head->val + carry;
        int digit = sum%10;
        carry = sum/10;
        head->val = digit;
        return carry;
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
    ListNode* doubleIt(ListNode* head) {
        //Approach-2 -> iterative -> T.C - O(n) , S.C - O(1)
        head = reverseList(head);
        int carry = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp) {
            int sum = 2*temp->val + carry;
            int digit = sum%10;
            carry = sum/10;
            temp->val = digit;

            prev = temp;
            temp = temp->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }

        head = reverseList(head);

        return head;



        // Approach-1 -> Recursion -> T.C - O(n), S.C - O(n)

        // int carry = solve(head);
        // if(carry) {
        //     ListNode* newNode = new ListNode(carry);
        //     newNode->next = head;
        //     head = newNode;
        // }

        // return head;
    }
};