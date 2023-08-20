// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

class Solution {
public:

    ListNode* reverse(ListNode* root){
        ListNode* curr= root;
        ListNode* forward = NULL;
        ListNode* prev = NULL;

        while(curr!=NULL){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        return prev;
    }

    void reorderList(ListNode* head) {


        if(head==NULL || head->next==NULL) return;

        ListNode* slow =head;
        ListNode* fast = head;
        ListNode* slow_prev =NULL;


        ///////// slow and fast pointer in order to find the mid element and reverse it

        while(fast!=NULL && fast->next!=NULL){
            slow_prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }


        ListNode* h1 = head;
        ListNode* h2 = NULL;


        ///////////////////////////////

        if(fast==NULL){
            h2 = reverse(slow);
            slow_prev->next=NULL;
        }else{
            h2=reverse(slow->next);
            slow->next=NULL;
        }


        ListNode* next1 = h1->next;
        ListNode* next2 = h2->next;



        //////////Joining them one by one 


        while(h1!=NULL && h2!=NULL){
            next1 = h1->next;
            next2 = h2->next;

            h1->next = h2;
            h2->next = next1;

            h1 = next1;
            h2 = next2;
        }

    }
};
