// Given a number n, find the value of below expression:
//             f(n-1)*f(n+1) - f(n)*f(n)    where f(n) is nth Fibonacci. 


class Solution{
	public:
   	int evaluate_exp(int n){
   	    // Code here
   	    
   	    if(n%2==0) return 1;
   	    return -1;
   	}    
};
