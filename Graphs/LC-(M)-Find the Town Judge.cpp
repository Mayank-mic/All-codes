// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. 
// If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.


// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {

//             vector<int> indeg(n, 0);

//             for(auto it: trust){
//                 indeg[it[1]-1]++;
//                 indeg[it[0]-1]--;
//             }


//             for(int i=0;i<n;++i){
//                 if(indeg[i]==n-1) return i+1;
//             }


//             return -1;


//     }
// };

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        if((n!=1) && trust.empty()) return -1;
        map <int,int> mp;
        int k=-1;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][1]]++;
        }
        for(auto it:mp) {
            if(it.second==n-1) k=it.first;
        }
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==k) return -1;
        }
        return k;
    }
};
