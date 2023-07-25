// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.


class Solution {
public:

    ListNode* reverse(ListNode* root){
        ListNode* prev=NULL;
        ListNode* curr= root;
        ListNode* nex=NULL;

        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }

        return prev;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==NULL || left>=right) return head;
        int lefty=left;

        right-=left;
        

        ListNode* temp = new ListNode(-1);

        ListNode* start=head;


        while(start!=NULL && --left){
            temp=start;
            start=start->next;
        }

        ListNode* start2=start;
        

        while( start2!=NULL && right-- ){
            start2=start2->next;
        }

        ListNode* endpoint=NULL;

        if(start2!=NULL) {
            endpoint=start2->next;
            start2->next=NULL;
        }

        temp->next= reverse(start);
        ListNode* point =temp->next;

        while(temp->next!=NULL){
            temp=temp->next;
        }

        if(temp!=NULL) temp->next= endpoint;

        if(lefty==1) return point;

        return head;

    }
};
