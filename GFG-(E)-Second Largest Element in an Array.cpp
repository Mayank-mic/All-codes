// Given an array Arr of size N, print second largest distinct element from an array.

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    
	    int prev=INT_MIN;
	    int maxi=INT_MIN;
	    
	    
	    for(int i=0;i<n;++i){
	        
	        if(arr[i]>maxi){
	            prev=maxi;
	            maxi=arr[i];
	        }else if(arr[i]<maxi && arr[i]>prev){
	            prev=arr[i];
	        }
	        
	    }
	    
	    if(prev==INT_MIN) return -1;
	    return prev;
	    
	    
	}
};
