// Given the head of a linked list head, in which each node contains an integer value.

// Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

// Return the linked list after insertion.

// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.




class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;


        ListNode* slow=head;
        ListNode* fast=head->next;


        while(fast!=NULL){
            ListNode* n = new ListNode(__gcd(slow->val, fast->val));
            slow->next = n;
            n->next=fast;
            slow=fast;
            fast=fast->next;
        }


        return head;
    }
};
