// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> nums;
        int n = lists.size();
        if(n==0) return NULL;

        for(int i=0;i<n;++i){
            
            ListNode* temp = lists[i];

            while(temp!=NULL){
                nums.push_back(temp->val);
                temp=temp->next;
            }
        }

        sort(nums.begin(), nums.end());

        ListNode* head = NULL;
        ListNode* temp = NULL;

        for(int i=0;i<nums.size();++i){
            if(i==0){
                 ListNode* n = new ListNode(nums[i]);
                 head = n;
                 temp=head;
            }else{
                ListNode* n = new ListNode(nums[i]);
                temp->next=n;
                temp=temp->next;
            }

        }


        return head;
    }
};
