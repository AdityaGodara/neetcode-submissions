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

    ListNode* reverseLL(ListNode* temp){
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp && k > 0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp){
            ListNode* kthNode = getKthNode(temp, k);
            
            if(!kthNode){
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
