// You are given two linked lists: list1 and list2 of sizes n and m respectively.

// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

// The blue edges and nodes in the following figure indicate the result:






class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {


        ListNode* temp1 = list1;
        b=b-a;

        while(a>1){
            temp1=temp1->next;
            a--;
        }

        ListNode* temp2 = temp1->next;

        temp1->next=list2;

        while(temp1->next!=NULL){
            temp1=temp1->next;
        }

        while(b>0){
            temp2=temp2->next;
            b--;
        }

        temp2=temp2->next;

        temp1->next=temp2;

        return list1;
        
    }
};
