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
    bool hasCycle(ListNode* head) {
        ListNode* one = head;
        ListNode* two = head;

        while(two != NULL && two->next != NULL){
            one = one->next;
            two = two->next->next;

            if(one==two) return true;
        }

        return false;
    }
};
