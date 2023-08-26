// You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

// i < j < k,
// nums[j] - nums[i] == diff, and
// nums[k] - nums[j] == diff.
// Return the number of unique arithmetic triplets.



class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        

int counter=0;
        int n = nums.size();


        for(int i=0;i<n-2;++i){
            for(int j=1;j<n-1;++j){
                if(nums[j]-nums[i]==diff){
                    for(int k=j+1;k<n;++k){
                        if(nums[k]-nums[j]==diff) counter++;
                }
                }
                
            }
        }


            return counter;


    }
};
