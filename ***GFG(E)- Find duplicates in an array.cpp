// Given an array a[] of size N which contains elements from 0 to N-1,
// you need to find all the elements occurring more than once in the given array. Return the answer in ascending order.

// Note: The extra space is only for the array to be returned.
// Try and perform all operations within the provided array.


class Solution{
  public:
    vector<int> duplicates(int numRay[], int n) {
        // code here
        
        vector<int> ans;
        
            for (int i = 0; i < n; i++) {
                int index= numRay[i];
                numRay[index % n] = numRay[index% n] + n;
            }
   
            for (int i = 0; i < n; i++) {
                if (numRay[i] >= n * 2) {
                    ans.push_back(i);
                }
            }
                
                
                
                if(ans.size()==0) return {-1};
                return ans;

    }
};
