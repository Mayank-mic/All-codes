// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. 
// No two characters may map to the same character, but a character may map to itself.



class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp;
        set<char> compa;

        int len=s.length();

        for(int i=0;i<len;++i){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]==t[i]) continue;
                return false;
            }

            if(compa.find(t[i])!=compa.end()) return false;

            mp[s[i]]=t[i];
            compa.insert(t[i]);

        }
        return true;
        
    }
};
