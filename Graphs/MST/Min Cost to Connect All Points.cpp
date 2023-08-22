// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.






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
            if(parent[node]==node) return node;
            return parent[node] = findUPar(parent[node]);
        }


        void ubs(int u ,int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_v== ulp_u) return;
            else if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
        }


    };


    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> grid;

        int v = points.size();

        vector<pair<int, pair<int, int>>> edges;


        for(int i=0;i<v-1;++i){
            for(int j=i+1;j<v;++j){
                int adjNode = j;
                int wt = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                int node = i;


                edges.push_back({wt, {node, adjNode}});
            }
        }

        dsu ds(v);

        sort(edges.begin(), edges.end());

        int mstWt = 0;

        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;


            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt+=wt;
                ds.ubs(u, v);
            }
        }


        return mstWt;
        
    }
};
