// Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

// answer.length == nums.length.
// answer[i] = |leftSum[i] - rightSum[i]|.
// Where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return the array answer.


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int sum=0;
        int n= nums.size();

        int leftsum=0;

        for(int i=0;i<n;++i){
            sum+=nums[i];
        }

        vector<int> ans;

        for(int i=0;i<n;++i){
            sum-=nums[i];

            ans.push_back(abs(leftsum-sum));

            leftsum+=nums[i];
        }


        return ans;
        
    }
};
