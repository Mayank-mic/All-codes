// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.




class Solution {
public:

    ListNode* reverse(ListNode* temp){
        ListNode* curr = temp;
        ListNode* prev = NULL;
        ListNode* nex = NULL;

        while(curr!=NULL){
            nex = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }

        return prev;
    }


    int pairSum(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast = head->next;

        while(fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* temp = slow->next;

        ListNode* s2 = reverse(temp);

        slow->next=NULL;

        int sum =-1;

        while(s2!=NULL && head!=NULL){
            sum=max(sum, s2->val+head->val);
            s2=s2->next;
            head=head->next;
        }


        return sum;

    }
};
