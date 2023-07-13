// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.


string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans="";
        
        for(int i=1; i< S.length();++i){
            if(S[i]!=S[i-1]){
                ans+=S[i-1];
            }
        }
        ans+=S[S.length()-1];
        
        return ans;
        
    }
