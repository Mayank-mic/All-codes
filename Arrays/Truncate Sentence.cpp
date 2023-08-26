// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).

// For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
// You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.



class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";

        int counter=0;

        string temp="";
        int i=0;

        while(i<s.length()){

            while(i<s.length() && s[i]!=32){
                temp+=s[i];
                ++i;
            }
        
            if(s[i]==32) ++i;
            ans+=temp;
            temp="";
            counter++;
            if(counter==k) break;
            ans+=" ";
        }


        return ans;
        
    }
};
