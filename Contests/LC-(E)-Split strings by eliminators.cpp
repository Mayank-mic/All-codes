// Given an array of strings words and a character separator, split each string in words by separator.

// Return an array of strings containing the new strings formed after the splits, excluding empty strings.

// Notes

// separator is used to determine where the split should occur, but it is not included as part of the resulting strings.
// A split may result in more than two strings.
// The resulting strings must maintain the same order as they were initially given.


class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        
        int n= words.size();
        vector<string> ult;
        
        for(int i=0;i<n;++i){
            string ans="";
            int j=0;
            int len=words[i].length();
            
            while(j<len){
                if(words[i][j]==separator){
                    if(ans!="") ult.push_back(ans);
                    ans="";
                }else{
                    ans+=words[i][j];
                }
                ++j;
            }
            if(words[i][len-1] && ans!="") ult.push_back(ans);
        }
        
        
        
        return ult;
        
    }
};
