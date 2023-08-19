// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.


class Solution {
public:

    static bool comp(vector<int>a, vector<int> b){
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), comp);


        int i=0;
        int j=1;
        int count=1;

        int n= pairs.size();

        while(j<n){
            if(pairs[i][1]<pairs[j][0]){
                count++;
                i=j;
            }

            j++;
        }


        return count;
        
    }
};
