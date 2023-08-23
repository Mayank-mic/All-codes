// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int first_max = INT_MIN;
        int ind=-1;

        for(int i=0;i<n;++i){
            if(nums[i]>first_max){
                first_max = max(first_max, nums[i]);
                ind=i;
            }
            
        }

        int sec_max = INT_MIN;
        for(int i=0;i<n;++i){
            if(i!=ind)
            sec_max = max(sec_max, nums[i]);
        }



        return (first_max-1)*(sec_max-1);
    }
};
