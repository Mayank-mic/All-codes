// You are given a positive integer array nums.

// The element sum is the sum of all the elements in nums.
// The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
// Return the absolute difference between the element sum and digit sum of nums.

// Note that the absolute difference between two integers x and y is defined as |x - y|.


class Solution {
public:
    int differenceOfSum(vector<int>& nums) {

        int all_sum=0;

        int each_sum=0;

        int n = nums.size();

        for(int i=0;i<n;++i){
            all_sum+=nums[i];
            int temp = nums[i];

            while(temp!=0){
                each_sum+=temp%10;
                temp/=10;
            }
        }


        return abs(all_sum-each_sum);
        
    }
};
