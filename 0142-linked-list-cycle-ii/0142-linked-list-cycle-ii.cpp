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
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
                if(fast == slow) {
                    break;
                }
            }
        }

        if(!fast) return NULL;

        slow = head;

        while(slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;



        // unordered_map<ListNode*, bool> vis;

        // ListNode* temp = head;
        // while(temp) {
        //     if(vis[temp]) {
        //         return temp;
        //     }

        //     vis[temp] = true;
        //     temp = temp->next;
        // }

        // return NULL;
    }
};