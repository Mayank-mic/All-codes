// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.



class Solution {
public:

    ListNode* removeZeroSumSublists(ListNode* head) {

        vector<int> v;
        while(head!=NULL){
            if(head->val!=0){
                v.push_back(head->val);
            }
            head=head->next;
        }

        for(int i=0;i<v.size();++i){
            int sum = v[i];
            for(int j=i+1;j<v.size();++j){
                sum+=v[j];

                if(sum==0){
                    v.erase(v.begin()+i, v.begin()+j+1);
                    i--;
                    break;
                }
            }
        }
        
        if(v.size()==1 && v[0]==0) return NULL;


        ListNode* head1 = NULL;
        ListNode* tail =NULL;

        int i=0;

        while(i<v.size()){
            ListNode* newN = new ListNode(v[i]);

            if(head1 == NULL){
                head1 = newN;
                tail = newN;
            }else{
                tail->next=newN;
                tail = newN;
            }
            ++i;
        }


        return head1;

    }
};
