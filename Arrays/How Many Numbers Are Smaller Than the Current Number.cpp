// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
// That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

// Return the answer in an array.



class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n= nums.size();

        vector<int> ans;

        for(int i=0;i<n;++i){
            int counter=0;
            for(int j=0;j<n;++j){
                if(i!=j && nums[i]>nums[j]){
                    counter++;
                }
            }
            ans.push_back(counter);
        }

        return ans;
    }
};
