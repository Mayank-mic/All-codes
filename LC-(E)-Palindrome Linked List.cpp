// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        string check="";

        ListNode* temp= head;

        while(temp!=NULL){
            check+=temp->val;
            temp=temp->next;
        }
        int len=check.length();

        for(int i=0;i<len;++i){
            if(check[i]!=check[len-i-1]) return false;
        }

        return true;
        
    }
};
