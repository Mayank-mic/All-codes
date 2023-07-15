// Given an array of integers of size N and a number K., 
// You must modify array arr[] exactly K number of times. 
// Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. 
// You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
        sort(a, a+n);
        
        int cnt_neg=0;
        
        for(int i=0;i<n;++i){
            if(a[i]<=0) cnt_neg++;
        }
        
        if(cnt_neg>=k){
            for(int i=0;i<k;++i){
                a[i]=a[i]*(-1);
            }
        }else{
            for(int i=0;i<cnt_neg;++i){
                a[i]=a[i]*(-1);
            }
            if((k-cnt_neg)%2!=0){
                sort(a, a+n);
                a[0]=a[0]*(-1);
            }
        }
        
        
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=a[i];
        }
        
        return sum;
        
    }
};
