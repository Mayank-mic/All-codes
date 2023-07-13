// Given an array a[ ] of N elements. Consider array as a circular array i.e. element after an is a1.
// The task is to find maximum sum of the absolute difference between consecutive elements with rearrangement of array elements allowed i.e. 
// after any rearrangement of array elements find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|.

long long int maxSum(int arr[], int n)
{
    
    sort(arr, arr+n);
    
    int sum=0;
    
        for(int i=0;i<n/2;++i){
            sum-=2*arr[i];
        }
        
        int i=-1;
        
        if(n%2==0) i=n/2;
        else i=n/2+1;
        
        
        for(;i<n;++i){
            sum+=2*arr[i];
        }
        
        return sum;

}
