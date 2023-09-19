// // Given a linked list of size N. The task is to complete the function countNodesinLoop() 
// that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. 
// C is the position of the node to which the last node is connected. If it is 0 then no loop.



int countNodesinLoop(struct Node *head)
{
    // Code here
    
    if(head->next==NULL) return 0;
    
    struct Node* slow = head;
    struct Node* fast = head->next;
    
    
    while(slow!=fast){
        
        if(fast->next==NULL || fast->next->next==NULL) return 0;
        
        slow= slow->next;
        fast = fast->next->next;
    }
    
    
    struct Node* temp =fast->next;
    
    
    while(head!=temp){
        head=head->next;
        temp=temp->next;
    }
    
    
    int length = 1;
    temp=temp->next;
    
    while(temp!=head){
        length++;
        temp=temp->next;
    }
    
    
    return length;
    
}
