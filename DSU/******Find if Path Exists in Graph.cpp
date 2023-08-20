// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex source to vertex destination.

// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.



class Solution {
public:

    class dsu{

        public:

        vector<int> parent, size;

        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i=0;i<=n;++i){
                parent[i]=i;
            }
        }


        int findUPar(int node){
            if(node==parent[node]) return node;
            else return parent[node]=findUPar(parent[node]);
        }


        void ubs(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);


            if(ulp_v==ulp_u) return;
            else if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }


    };

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        dsu ds(n);


        for(int i=0;i<edges.size();++i){
            ds.ubs(edges[i][0], edges[i][1]);
        }

        return ds.findUPar(source)==ds.findUPar(destination);
        
    }
};
