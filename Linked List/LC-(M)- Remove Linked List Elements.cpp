// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* one = new ListNode(-1);

        ListNode* two=head;

        while(two!=NULL){
            if(two->val==val){
                while(two!=NULL && two->val==val){
                    two=two->next;
                }
                one->next=two;
            }
            one=two;
            
            if(head->val==val) head=one;

            if(two==NULL) break;
            two=two->next;
        }

        return head;
        
    }
};
