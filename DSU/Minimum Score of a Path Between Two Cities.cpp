// You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

// The score of a path between two cities is defined as the minimum distance of a road in this path.

// Return the minimum possible score of a path between cities 1 and n.

// Note:

// A path is a sequence of roads between two cities.
// It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
// The test cases are generated such that there is at least one path between 1 and n..



class Solution {
public:

    class dsu{
        public:
        vector<int> parent;
        vector<int> size;

        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i=0;i<=n;++i){
                parent[i]=i;
            }
        }


        int findUPar(int node){
            if(parent[node]==node) return node;
            return parent[node]=findUPar(parent[node]);
        }

        void ubs(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_v==ulp_u) return;
            else if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    };



    int minScore(int n, vector<vector<int>>& roads) {
        

        int le = roads.size();

        dsu ds(n);

        vector<int> mini(n+1, INT_MAX);
        
        int ans=INT_MAX;


        for(int i=0;i<le;++i){
            ds.ubs(roads[i][0], roads[i][1]);
            mini[roads[i][0]] = min(mini[roads[i][0]], roads[i][2]);
            mini[roads[i][1]] = min(mini[roads[i][1]], roads[i][2]);
        }

        for(int i=1;i<n+1;++i){
            if(ds.findUPar(i)==ds.findUPar(1)){
                ans = min(ans, mini[i]);
            }
        }

        return ans;


    }
};
