// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

// A string is represented by an array if the array elements concatenated in order forms the string.




class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s1 = "";
        string s2 = "";


        for(auto it: word1){
            s1+=it;
        }

        for(auto it: word2){
            s2+=it;
        }


        return s1==s2;
        
    }
};
