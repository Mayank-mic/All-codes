// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> temp;

        if(nums1.size()<nums2.size()){
            temp = nums1;
            nums1=nums2;
            nums2=temp;
        }


        unordered_map<int, int> mp;

        for(auto it: nums1){
            mp[it]++;
        }


        vector<int> ans;

        for(auto it: nums2){
            if(mp[it]>0) ans.push_back(it);
            mp[it]--;
        }

        return ans;

        
    }
};
