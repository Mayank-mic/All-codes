// Given the head of a linked list, return the list after sorting it in ascending order.



class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }


        if(l1){
            curr->next=l1;
        }


        if(l2){
            curr->next = l2;
        }


        return ptr->next;

    }



    ListNode* sortList(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;

        ListNode* temp = NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next=NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
        
    }
};
