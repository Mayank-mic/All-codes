// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] 
// represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, 
// and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.




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

            return parent[node]= findUPar(parent[node]);
        }


        void ubs(int u, int v){
            int ulp_v = findUPar(v);
            int ulp_u = findUPar(u);


            if(ulp_v==ulp_u) return;
            else if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u]= ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }


    };



    int makeConnected(int n, vector<vector<int>>& connections) {

        int extras=0;

        int conn =0;

        dsu ds(n);

        for(int i=0;i<connections.size();++i){
            
            if(ds.findUPar(connections[i][0])==ds.findUPar(connections[i][1])){
                extras++;
            }else{
                ds.ubs(connections[i][0], connections[i][1]);
                conn++;
            }
        }

        if( (extras+conn) >= (n-1) ) return (n-1)-conn;
        return -1; 

    }
};











/////////////      Method 2;

class Solution {
    void dfs(vector<int> adj[], vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
        int len = arr.size();
        if(len<n-1) return -1;
         vector<int> adj[n];
        for(auto v : arr)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0; i<n; i++)
        if(!visited[i])
        {
            dfs(adj, visited, i);
            ans++;
        }
        return ans - 1;
    }
};
