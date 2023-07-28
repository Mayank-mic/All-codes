// Given an array arr[] of size n, find the first repeating element. 
// The element should occur more than once and the index of its first occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 




class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int, int> mp;
        
        int ind=INT_MAX;;
        
        
        for(int i=0;i<n;++i){
            if(mp.find(arr[i])!=mp.end()){
                ind=min(ind, mp[arr[i]]);
                continue;
            }
            
            mp[arr[i]]=i+1;
        }
        
        if(ind==INT_MAX) return -1;
        return ind;
        // code here
    }
};
