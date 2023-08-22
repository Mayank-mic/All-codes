// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

class Solution {
public:
    class dsu{
        public:
            vector<int> parent;
            vector<int> size;

            dsu(int n){
                parent.resize(n+1);
                size.resize(n+1,1);


                for(int i=0;i<=n;++i){
                    parent[i]=i;
                }
            }


            int findUPar(int node){
                if(parent[node]==node) return node;
                return parent[node]= findUPar(parent[node]);
            }


            void ubs(int u, int v){
                int ulp_u = parent[u];
                int ulp_v = parent[v];

                if(ulp_u== ulp_v) return;
                else if(size[ulp_u] > size[ulp_v]){
                    parent[ulp_v] = ulp_u;
                    size[ulp_u]+=size[ulp_v];
                }else{
                    parent[ulp_u]=ulp_v;
                    size[ulp_v]+=size[ulp_u];
                }
            }
            
    };


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                int n = edges.size();

                dsu ds(n);

                for(int i=0;i<n;++i){
                    if(ds.findUPar(edges[i][0])== ds.findUPar(edges[i][1])){
                        return {edges[i][0], edges[i][1]};
                    }

                    ds.ubs(edges[i][0], edges[i][1]);
                }


                return {edges[n-1][0], edges[n-1][1]};      
    }
};
