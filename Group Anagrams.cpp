// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string> > mp;

        vector<vector<string>> ans;

        for(auto it: strs){
            string temp=it;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(it);
        }


        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};
