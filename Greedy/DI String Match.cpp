// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// s[i] == 'I' if perm[i] < perm[i + 1], and
// s[i] == 'D' if perm[i] > perm[i + 1].
// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.






class Solution {
public:
    vector<int> diStringMatch(string s) {

        vector<int> ans;

        int i=0;
        int j = s.length();



        for(int k=0;k<s.length();++k){
            if(s[k]=='I'){
                ans.push_back(i);
                ++i;
            }else{
                ans.push_back(j);
                j--;
            } 
        }

        ans.push_back(j--);


        return ans;
        
    }
};
