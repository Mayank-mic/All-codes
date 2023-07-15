// Given a string S, check if it is palindrome or not.
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    
	    int low =0; 
	    int high = S.length()-1;
	    
	    
	    while(low<=high){
	        if(S[low]!=S[high]) return 0;
	        low++;
	        high--;
	    }
	    
	    return 1;
	    
	    
	}

};
