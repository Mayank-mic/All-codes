// You are given a string s consisting of n characters which are either 'X' or 'O'.

// A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.

// Return the minimum number of moves required so that all the characters of s are converted to 'O'.



class Solution {
public:
    int minimumMoves(string s) {

        int l = s.length();

        int i=0;
        int ans=0;
        while(i<=l-1){

            if(s[i]=='X'){
                ans++;
                i=i+3;
            }else{
                i++;
            }
        }

        return ans;
        
    }
};
