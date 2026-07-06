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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> vis;

        ListNode* temp = head;
        while(temp) {
            if(vis[temp]) {
                return temp;
            }

            vis[temp] = true;
            temp = temp->next;
        }

        return NULL;
    }
};