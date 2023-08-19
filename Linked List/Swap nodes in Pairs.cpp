// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        

        if(head==NULL || head->next==NULL) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        ListNode* temp = second->next;

        second->next=first;
        first->next= swapPairs(temp);

        return second;

    }
};
