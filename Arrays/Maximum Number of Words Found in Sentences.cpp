// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

// You are given an array of strings sentences, where each sentences[i] represents a single sentence.

// Return the maximum number of words that appear in a single sentence.



class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int maxi = INT_MIN;

        for(int i=0;i<sentences.size();++i){
            int counter=0;
            for(int j=0;j<sentences[i].length();++j){
                if(sentences[i][j]==' ') counter++;
            }
            counter++;
            maxi=max(maxi, counter);
        }
        return maxi;
    }
};
