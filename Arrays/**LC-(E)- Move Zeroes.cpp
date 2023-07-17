// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.


// Dutch National Flag Algo.


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n= nums.size();

        int i= -1;
        int j=0;

        if(n==1 || n==0) return;

        cout<<n<<endl;

        while(j<n){
            if(nums[j]!=0){
                ++i;
                swap(nums[i], nums[j]);
            }
            ++j;
        }
        
    }
};
