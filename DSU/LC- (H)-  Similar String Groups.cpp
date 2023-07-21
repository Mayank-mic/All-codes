// Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent 
// by swapping at most two letters (in distinct positions) within the string X.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, 
// but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}. 
// Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word 
// is in the group if and only if it is similar to at least one other word in the group.

// We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

Method -1

class Solution {
public:

    class dsu{
        public:

        vector<int> parent;
        vector<int> size;

        dsu(int n){
            parent.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i=0;i<=n;++i){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }


        void ubs(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);

            if(ulp_u==ulp_v) return;
            if(size[ulp_v]<size[ulp_u]){
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }

        }

    };

    bool isSimilar(string a, string b){
        int l = a.length();

        int diff=0;

        for(int i=0;i<l;++i){
            if(a[i]!=b[i]) diff++;
        }

        if(diff==2 || diff==0) return true;
        return false;
    }


    int numSimilarGroups(vector<string>& strs) {

        int n=strs.size();

        dsu ds(n-1);

        int groups=n;

        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(isSimilar(strs[i], strs[j])==true && ds.findUPar(i)!=ds.findUPar(j)){
                    ds.ubs(i, j);
                    groups--;
                }
            }
        }

        return groups;

        
    }
};



//////////////////  ????????????//////////???????????//////////??????????????////

Method 2

class Solution {
public:
    bool similar(string &s,string &t){
        int dif=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                dif++;
            }
        }
        return dif<=2;
    }
    void dfs(int node,vector<int>&vis,vector<vector<int>>&graph){
        vis[node]=1;
        for(auto&child:graph[node]){
            if(!vis[child]){
                dfs(child,vis,graph);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>graph(strs.size());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(similar(strs[i],strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph);
                ans++;
            }
        }
        return ans;
    }
};
