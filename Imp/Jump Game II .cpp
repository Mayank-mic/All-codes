// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



class Solution {
public:

    /*
    int jump(vector<int>& nums) {

        int n= nums.size();

        if(n==1) return 0;
        if(n==2) return 1;

        vector<int> dp(n, INT_MAX);
        dp[0]=0;

        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if((i-j)<=nums[j]){
                    dp[i]=min(dp[i], 1+dp[j]);
                }
            }
        }
        
        return dp[n-1];

    }*/


    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }

    
};
