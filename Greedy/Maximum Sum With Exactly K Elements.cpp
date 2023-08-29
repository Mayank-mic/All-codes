// You are given a 0-indexed integer array nums and an integer k. Your task is to perform the following operation exactly k times in order to maximize your score:

// Select an element m from nums.
// Remove the selected element m from the array.
// Add a new element with a value of m + 1 to the array.
// Increase your score by m.
// Return the maximum score you can achieve after performing the operation exactly k times.



class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {

        int max_num = 0;


        for(int i=0;i<nums.size();++i){
            max_num = max(max_num, nums[i]);
        }


        return max_num*k +(k*(k-1))/2;
        
    }
};
