// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible 
// for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in str1 should map to the same character in str2


class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        
        unordered_map<char, char> mp;
        
        int len1 = str1.length();
        int len2 = str2.length();
        
        unordered_set<char> s1;
        unordered_set<char> s2;
        
        
        for(int i=0;i<len1;++i){
            s1.insert(str1[i]);
            s2.insert(str2[i]);
        }
        
        if(s1.size()!=s2.size()) return false;
        
        if(len1!=len2) return false;
        
        for(int i=0;i<len1;++i){
            
            char one = str1[i];
            char two = str2[i];
            
            if(mp.find(one)!=mp.end()){
                if(mp[one]!=two) return false;
            }else{
                mp[one]=two; 
            }    
        }
        
        return true;
        
    }
    
    
    
    // bool areIsomorphic(string str1, string str2)
    // {
        
    //     // Your code here
    //     if(str1.length()!=str2.length())
    //     return false;
    //     unordered_map<char,char>mp,mp2;

    //     for(int i=0;i<str1.length();i++)
    //     {
    //         auto it=mp.find(str1[i]);
    //         if(it!=mp.end())
    //         {
    //             if(it->second!=str2[i])
    //             return false;
    //         }
    //         else
    //         {
    //             mp[str1[i]]=str2[i];
    //         }
    //     }
        
        

    //     for(int i=0;i<str2.length();i++)
    //     {
    //         auto it=mp2.find(str2[i]);
    //         if(it!=mp2.end())
    //         {
    //             if(it->second!=str1[i])
    //             return false;
    //         }
    //         else
    //         {
    //             mp2[str2[i]]=str1[i];
    //         }
    //     }
    //     return true;
        
    // }
};
