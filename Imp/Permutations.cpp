//Method 2 to permute distinct elements

sort(nums.begin(), nums.end());

do{
  ans.push_back(nums);
} while(next_permutation(nums.begin(), nums.end()));




// Permutations 1 where all the elements are distinct

class Solution {
public:

    void helper(vector<vector<int>>&ans, vector<int>&a, int idx){
        if(idx==a.size()){
            ans.push_back(a);
            return;
        }

        for(int i= idx; i<a.size();++i){
            swap(a[i], a[idx]);
            helper(ans, a, idx+1);
            swap(a[i], a[idx]);
        }

        return;
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans,nums, 0);
        return ans;
    }
};







// Permutations 2 wherer duplicate elements are present 

class Solution {
public:
    void helper(vector<int> a, vector<vector<int>>& ans, int idx){
        if(idx==a.size()){
            ans.push_back(a);
            return;
        }

        for(int i=idx;i<a.size();++i){
            if(i!=idx && a[i]==a[idx]) continue;

            swap(a[i], a[idx]);
            helper(a, ans, idx+1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        helper(nums, ans, 0);
    return ans;
        
    }
};
