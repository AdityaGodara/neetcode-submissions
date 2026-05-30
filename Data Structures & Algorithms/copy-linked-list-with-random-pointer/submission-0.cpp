/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node* temp = head->next;
        Node* copyStart = new Node(head->val);
        Node* copyTemp = copyStart;
        unordered_map<Node*,Node*> mpp;
        mpp[head] = copyStart;

        while(temp){
            Node* newCopy = new Node(temp->val);
            mpp[temp] = newCopy;
            copyTemp->next = newCopy;

            copyTemp = copyTemp->next;
            temp = temp->next;
        }
        temp = head;
        copyTemp = copyStart;
        while(temp){
            copyTemp->random = temp->random ? mpp[temp->random]: NULL;

            temp = temp->next;
            copyTemp = copyTemp->next;
        }

        return copyStart;

    }
};
