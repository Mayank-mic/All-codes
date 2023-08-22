// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

// The ith item is said to match the rule if one of the following is true:

// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.


class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

        int cas=-1;

        if(ruleKey=="type") cas=0;
        else if(ruleKey=="color") cas=1;
        else cas=2;

        int n = items.size();
        int counter=0;

        for(int i=0;i<n;++i){
            if(items[i][cas]==ruleValue) counter++;
        }

        return counter;
        
    }
};
