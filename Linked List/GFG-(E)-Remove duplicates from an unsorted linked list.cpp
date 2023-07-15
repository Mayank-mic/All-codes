// Given an unsorted linked list of N nodes. 
// The task is to remove duplicate elements from this unsorted Linked List.
// When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int> st;
     
     if(head->next==NULL || head==NULL) return head;
     
     Node* slow= head;
     Node* fast= head->next;
     
     st.insert(head->data);
     
     
     while(fast!=NULL){
         if(st.find(fast->data)!=st.end()){
             fast=fast->next;
         }else{
             st.insert(fast->data);
             slow->next=fast;
             fast=fast->next;
             slow=slow->next;
         }
     }
     
     slow->next=NULL;
     return head;
     
    }
};
