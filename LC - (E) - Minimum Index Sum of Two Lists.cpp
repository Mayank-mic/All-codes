// Given two arrays of strings list1 and list2, find the common strings with the least index sum.

// A common string is a string that appeared in both list1 and list2.

// A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] 
// then i + j should be the minimum value among all the other common strings.

// Return all the common strings with the least index sum. Return the answer in any order.


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string , int> mp;

        for(int i=0;i<list1.size();++i){
            mp[list1[i]]=i;
        }

        int mini = INT_MAX;
         vector<string> ans;

        for(int j=0;j<list2.size();++j){

            if(mp.find(list2[j])!= mp.end()){
                mp[list2[j]]+=j;

                if(mp[list2[j]] < mini){
                    mini = mp[list2[j]];
                    ans.clear();
                    ans.push_back(list2[j]);
                }else if(mini == mp[list2[j]]){
                    ans.push_back(list2[j]);
                }
            }

        }

        return ans;
    }
};
