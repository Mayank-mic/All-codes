// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c,
// then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.


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
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void ubs(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v= findUPar(v);

        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }


};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        //int m = isConnected[0].size;

        dsu ds(n);

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j]==1) ds.ubs(i, j);
            }
        }

        int cnt=0;

        for(int i=0;i<n;++i){
            if(ds.parent[i]==i) cnt++;
        }

        return cnt;

    }
};
