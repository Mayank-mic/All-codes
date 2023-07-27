// An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
// Given an array arr[] of size N, Return the index of any one of its peak elements.
// Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       
       if(arr[0]>=arr[1]) return 0;
       if(arr[n-1]>=arr[n-2]) return n-1;
       
       int low=0;
       int high=n-1;
       
       
       int mid=0;
       
       
       while(low<=high){
           
           mid=(low+high)/2;
           
           if( mid-1>=0 && mid+1<=n-1 && arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1]){
               return mid;
           }else if(arr[mid-1]>=arr[mid]){
               high=mid;
           }else if(arr[mid+1]>=arr[mid]){
                low=mid;   
            }
           
       }
       
       
    }
};
