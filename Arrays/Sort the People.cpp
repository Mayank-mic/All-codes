// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

// For each index i, names[i] and heights[i] denote the name and height of the ith person.

// Return names sorted in descending order by the people's heights.


class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int, string>> mp;

        for(int i =0; i<names.size();++i){
            mp.push_back({heights[i], names[i]});
        }


        sort(mp.begin(), mp.end(), greater<pair<int, string>>());

        vector<string> ans;

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;


        
    }
};
