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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        while(left && right) {
            if(left->val < right->val) {
                tail->next = left;
                tail = left;
                left = left->next;
                tail->next = NULL;
            }
            else{
                tail->next = right;
                tail = right;
                right = right->next;
                tail->next = NULL;
            }
        }

        if(left) {
            tail->next = left;
        }
        if(right) {
            tail->next = right;
        }

        return head->next;
    }
    ListNode* solve(vector<ListNode*>& lists, int s, int e) {
        if(s > e) return NULL;
        if(s == e) return lists[s];

        int mid = s + (e - s)/2;

        ListNode* left = solve(lists, s, mid);
        ListNode* right = solve(lists, mid+1, e);

        return merge(left, right);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = 0;
        int e = lists.size()-1;

        return solve(lists, s, e);
    }
};