// You are given a 0-indexed array nums consisting of positive integers.

// You can do the following operation on the array any number of times:

// Choose an integer i such that 0 <= i < nums.length - 1 and nums[i] <= nums[i + 1].
//   Replace the element nums[i + 1] with nums[i] + nums[i + 1] and delete the element nums[i] from the array.
// Return the value of the largest element that you can possibly obtain in the final array.


class Solution {
public:
    long long max(long long a, long long b){
        if(a>b) return a;
        return b;
    }
        
    
    long long maxArrayValue(vector<int>& nums) {
        
        
        long long sum=0;
        
        vector<long long> ans;
        
        long long maxi=INT_MIN;
        
        int n=nums.size();
        
        
        for(int i=0;i<n;++i){
            ans.push_back(nums[i]);
        }
        
        
        for(int i=n-1;i>0;--i){
            
            if(ans[i-1]<=ans[i]){
                ans[i-1]=ans[i-1]+ans[i];
            }
            

            maxi=max(maxi, ans[i]);
            
        }
        
        maxi=max(maxi, ans[0]);
        
        return maxi;
        
        
    }
};
