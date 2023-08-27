// You are given the head of a linked list with n nodes.

// For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.



class Solution {
public:

    ListNode* reve(ListNode* temp){
        ListNode* curr = temp;
        ListNode* prev = NULL;
        ListNode* nex = NULL;

        while(curr!=NULL){
            nex= curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }


        return prev;
    }


    vector<int> nextLargerNodes(ListNode* head) {


        ListNode* last = head;

        ListNode* rev = reve(last);

        vector<int> ans;

        int temp_max=0;

        stack<int> st;
        st.push(0);

        while(rev!=NULL){

            while(st.top()<=rev->val && st.top()!=0){
                st.pop();
            }
            
            ans.push_back(st.top());
            st.push(rev->val);

            rev=rev->next;

        }


        reverse(ans.begin(), ans.end());

        return ans;


    }
};
