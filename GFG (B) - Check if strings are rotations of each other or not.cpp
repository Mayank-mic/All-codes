// Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. 
// The characters in the strings are in lowercase.

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.

    bool areRotations(string s1,string s2)
    {
        
        int n=s1.length();

        for(int i=0;i<n;++i){
            if(s1==s2) return true;
            s1 = s1.substr(1, n-1) + s1[0];
        }
        
        return false;
        
    }
    
    /*
    bool areRotations(string s1,string s2){
        if(s1.size()!=s2.size()){
            return 0;
        }
        for(int i=0; i<s1.size(); i++){
            string a1 = s1.substr(i, s1.size()-i);
            string a2 = s2.substr(0, s1.size()-i);
            
            string b1 = s1.substr(0, i);
            string b2 = s2.substr(s1.size()-i, i);
            
            if(a1 == a2 && b1 == b2){
                return 1;
            }
        }
        return 0;
    }*/
};
