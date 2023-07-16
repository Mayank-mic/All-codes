// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, 
// return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.




class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word==endWord) return steps;

            for(int i=0;i<word.size();++i){
                char original = word[i];
                for(char ch='a'; ch<='z'; ++ch){
                    word[i]=ch;

                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
