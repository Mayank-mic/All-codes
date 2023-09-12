// Given a number N, check if a number is perfect or not. A number is said to be perfect if sum of all its factors excluding the number itself is equal to the number. Return 1 if the number is Perfect otherwise return 0.




int isPerfectNumber(long long N) {
        // code here
        
        
        if(N==1) return 0;
        
        long long sum = 1;
        
        for(int i=2; i<=sqrt(N); ++i){
            if(N%i==0) sum+=i+(N/i);
        }
        
        
        return sum==N;
        
    }
