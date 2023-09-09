// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.


class Solution {
public:
    string sortSentence(string s) {

        vector<string> store(10, ".");
        
        string temp ="";
        for(int i=0;i<s.length();++i){
            if(s[i]==32) continue;
            if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' ||s[i]=='6' || s[i]=='7' ||s[i]=='8' ||s[i]=='9'){
                store[s[i]-'0'] = temp;
                temp="";
                continue;
            }
            temp+=s[i];
        }

        string ans="";

        for(int i=0;i<10;++i){
            if(store[i]==".") continue;
            ans+=store[i]+" ";
        }

        ans.pop_back();
        return ans;
        
    }
};
