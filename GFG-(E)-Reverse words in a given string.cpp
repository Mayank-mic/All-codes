// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        
        vector<string> str;
        int len=S.length();
        
        string temp;
        
        for(int i=0;i<len;++i){
            if(S[i]=='.' && temp!=""){
                str.push_back(temp);
                temp="";
            }
            else{
                temp+=S[i];
            }
        }
        
        
        if(S[len-1]!='.') str.push_back(temp);
        
        reverse(str.begin(), str.end());
        
        string ans="";
        
        
        for(int i=0;i<str.size();++i){
            if(i==str.size()-1) ans+=str[i];
            else ans+=str[i]+".";
        }
        
        
        
        return ans;
        
    } 
};
