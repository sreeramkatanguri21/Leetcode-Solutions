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
        if(head == NULL || head->next == NULL || head->next->next == NULL)  return head;

        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;

        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;


        // ListNode* odd = new ListNode(-1);
        // ListNode* oddTemp = odd;
        // ListNode* even = new ListNode(-1);
        // ListNode* evenTemp = even;

        // bool isOdd = true;
        // ListNode* temp = head;
        // while(temp) {
        //     ListNode* forward = temp->next;
        //     temp->next = NULL;

        //     if(isOdd) {
        //         oddTemp->next = temp;
        //         oddTemp = temp;
        //     }
        //     else {
        //         evenTemp->next = temp;
        //         evenTemp = temp;
        //     }

        //     isOdd = !isOdd;
        //     temp = forward;
        // }

        // oddTemp->next = even->next;

        // return head;

    }
};