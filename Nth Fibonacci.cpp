// Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

#define MOD 1000000007;

class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        
        if(n==1) return 0;
        

        vector<int> vec(n+1, 0);
        
        vec[1]=1;
        
        for(int i=3;i<=n+1;++i){
            vec[i-1]=(vec[i-2]+vec[i-3])%MOD;
        }
        
        return vec[n]%MOD;
        
    }
};
