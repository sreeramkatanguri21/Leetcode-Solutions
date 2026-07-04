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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
                if(slow == fast)  return true;
            }
        }
        return false;



        // unordered_map<ListNode*, bool> vis;
        // ListNode* temp = head;

        // while(temp) {
        //     if(vis[temp]) {
        //         return true;
        //     }

        //     vis[temp] = true;
        //     temp = temp->next;
        // }

        // return false;
    }
};