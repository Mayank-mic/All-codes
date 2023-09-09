// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> store(26, -1);


        for(int i =0 ;i<s.length();++i){
            if(store[s[i]-'a']==INT_MIN) continue;
            if(store[s[i]-'a']!=-1){
              store[s[i]-'a']=INT_MIN;
              continue;  
            }
            store[s[i]-'a']=i;
        }

        int ans=INT_MAX;

        for(auto it: store){
            if(it!=-1 && it!=INT_MIN){
                ans=min(ans, it);
            }
        }

        if(ans==INT_MAX) return -1;

        return ans;

    }
};
