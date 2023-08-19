// Given a node delete it from the string no head or start point is given.



class Solution {
public:
    void deleteNode(ListNode* node) {


        ListNode* n = node->next;
        node->val = n->val;
        node->next=n->next;
        
        
    }
};
