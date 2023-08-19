// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n= nums.size();

        if(n==1) return true;
        if(nums[0]==0) return false;

        for(int i=1;i<n;++i){
            nums[i]=max(nums[i]+i, nums[i-1]);
            if(nums[i]<=i && i!=n-1) return false;
        }
        

        return true;
    }
};
