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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* oddTemp = odd;
        ListNode* even = new ListNode(-1);
        ListNode* evenTemp = even;

        bool isOdd = true;
        ListNode* temp = head;
        while(temp) {
            ListNode* forward = temp->next;
            temp->next = NULL;

            if(isOdd) {
                oddTemp->next = temp;
                oddTemp = temp;
            }
            else {
                evenTemp->next = temp;
                evenTemp = temp;
            }

            isOdd = !isOdd;
            temp = forward;
        }

        oddTemp->next = even->next;

        return head;

    }
};