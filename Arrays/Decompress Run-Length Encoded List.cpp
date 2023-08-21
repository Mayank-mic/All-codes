// We are given a list nums of integers representing a list compressed with run-length encoding.

// Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.

// Return the decompressed list.



class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        for(int i=0;i<n;i+=2){
            int val = nums[i+1];
            int freq = nums[i];

            while(freq--){
                ans.push_back(val);
            }
        }


        return ans;
        
    }
};
