// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.


//Recursive:

class Solution {
public:
    int mymin(int a, int b){
        if(a<=b) return a;
        return b;
    } 

    void helper(vector<int>& nums, int i, int j, int x, int temp, int count, int& store){

        if(temp>x) return ;
        
        if(temp==x){
            store = mymin(store, count);
            return;
        }

        if(i>j) return;


        if(i<nums.size()){
            helper(nums, i+1, j, x, temp+nums[i], count+1, store);
        }

        if(j>=0){
            helper(nums, i, j-1, x, temp+nums[j], count+1, store);
        }
        return;
    }

    int minOperations(vector<int>& nums, int x) {
        int store =INT_MAX;
        helper(nums, 0, nums.size()-1, x, 0, 0, store);

        if(store==INT_MAX) return -1;
        return store;
    }
};



///////

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {


        int totalSum = 0;

        for(auto it: nums) totalSum+=it;

        int maxLength = -1;
        int currSum=0;

        for(int l=0, r=0; r<nums.size();++r){
            currSum +=nums[r];

            while(l<=r && currSum>totalSum-x) currSum-=nums[l++];

            if(currSum==totalSum-x){
                maxLength = max(maxLength, r-l+1);
            }

        }

         return maxLength ==-1? -1:nums.size()-maxLength;
        
    }
};
