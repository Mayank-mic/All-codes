// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.


// Method 1

   ListNode* deleteDuplicates(ListNode* head){

        if(head==NULL || head->next==NULL) return head;

        unordered_map<int, int> mp;

        ListNode* temp= head;

        while(temp!=NULL){

            mp[temp->val]++;
            temp=temp->next;
        }


        temp=head;
        ListNode* start=new ListNode(-1);

        ListNode* prev = start;

        while(temp!=NULL){
            if(mp[temp->val]>1){
                if(temp->next==NULL){
                    start->next=NULL;
                }
                temp=temp->next;
            }else{
                start->next=temp;
                start=temp;
                temp=temp->next;
            }
        }
        return prev->next;
    }


Method 2:

lass Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {


        ListNode* start = new ListNode(-1);
        start->next=head;
        ListNode* prev = start;


        while(head!=NULL){

            if(head->next!=NULL && head->val==head->next->val){
                while(head->next!=NULL && head->val == head->next->val) head= head->next;

                prev->next = head->next;
            }else{
                prev= prev->next;
            }

            head=head->next;


        }

        return start->next;
        
    }

};

