// Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

// Given a balanced string s, split it into some number of substrings such that:

// Each substring is balanced.
// Return the maximum number of balanced strings you can obtain.





class Solution {
public:
    int balancedStringSplit(string s) {


        int counter=0;
        
        int lR=0;
        int lL=0;

        int n = s.length();

        for(int i=0;i<n;++i){
            if(s[i]=='L') lL++;
            if(s[i]=='R') lR++;


            if(lL==lR) counter++;
        }


        return counter;
        
    }
};
