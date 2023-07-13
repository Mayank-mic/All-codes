// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        if(n==0) return false;
        if(n==1)return true;
        
        while(n>1){
            if(n%2!=0) return false;
            n=n/2;
        }
        
        return true;
        
    }
};
