// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).





class Solution {
public:
    int maximum69Number (int num) {


        string digi = to_string(num);

        int n = digi.length();

        for(int i=0;i<n;++i){
            if(digi[i]=='6'){
                digi[i]='9';
                break;
            }
        }

        return stoi(digi);
        
    }
};
