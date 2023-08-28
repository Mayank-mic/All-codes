// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.


class Solution {
public:
    int len(ListNode* temp){

        int x=0;
        
        while(temp!=NULL){
            temp=temp->next;
            x++;
        }

        return x;
    }


    ListNode* rev(ListNode* temp, int k, int div){

        if(div==0) return temp;
        int x = k;

        ListNode* curr = temp;
        ListNode* prev= NULL;
        ListNode* nex = NULL;

        while(curr!=NULL && k>0){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            k--;
        }
        div--;

        temp->next = rev(curr, x, div);

        return prev;
    }



    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        
        int length = len(temp);

        int count = length/k;

        ListNode* temp2 = head;

        return rev(temp2, k, count);
    }
};
