/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> vis;
        ListNode* temp = headA;

        while(temp) {
            vis[temp] = true;
            temp = temp->next;
        }

        temp = headB;

        while(temp) {
            if(vis[temp]) {
                return temp;
            }

            temp = temp->next;
        }

        return NULL;
    }
};