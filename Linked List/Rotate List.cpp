// Given the head of a linked list, rotate the list to the right by k places.

class Solution {
public:
    int len(ListNode* root){
        ListNode* temp =root;

        int counter=0;

        while(temp){
            temp=temp->next;
            counter++;
        }

        return counter;
        
    }


    ListNode* rotateRight(ListNode* head, int k) {


            if(head==NULL || head->next==NULL) return head;
            
            int size = len(head);

            k= k%size;

            int count = size-k;

            ListNode* start = head;
            ListNode* end = head;
            ListNode* nex =NULL;

            while(end->next!=NULL){
                end=end->next;
            }

            int num=0;

            while(num<count){
                end->next=start;
                nex=start->next;
                start->next=NULL;
                end=start;
                start=nex;
                num++;
            }   


            return  start;
    }
};
