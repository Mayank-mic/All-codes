// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// Implement the Solution class:

// Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
// int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

class Solution {
public:
    int size=1;
    ListNode* start =NULL;

    Solution(ListNode* head) {
        ListNode* temp =head;
        start = head;
        size = length(temp);
    }

    int length(ListNode* root){
        int x = 0;
        while(root!=NULL){
            root=root->next;
            x++;
        }
        return x;
    }
    
    int getRandom() {

        int ind = rand()%size;

        ListNode* follower = start;

        for(int i=0;i<ind;++i){
            follower = follower->next;
        }

        return follower->val;
        
    }
};
