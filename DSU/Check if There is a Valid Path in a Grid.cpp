



class DisjointSet{
public:
    vector<int>par,size;
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            par[i] = i;
        }
    }
    int findpar(int u){
        if(u == par[u]) return u;
        return par[u] = findpar(par[u]);
    }

    void unionBySize(int u, int v){
        u = findpar(u);
        v = findpar(v);

        if(u == v) return;

        if(size[u] >= size[v]){
            par[v] = u;
            size[u] += size[v];
        }
        else{
            par[u] = v;
            size[v] += size[u];
        }
    }
    
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int p = i * m + j;
                int p1 = (i-1)*m + j;  // 1
                int p2 = (i+1)*m + j;  // 1
                int p3 = i*m + (j+1);  // 2
                int p4 = i*m + (j-1);  // 2

                if(grid[i][j] == 1){
                    if(j+1 < m && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5) ){
                        ds.unionBySize(p,p3);
                    }
                    if(j-1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6) ){
                        ds.unionBySize(p,p4);
                    }
                }
                else if(grid[i][j] == 2){
                    if(i+1 < n && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6) ){
                        ds.unionBySize(p,p2);
                    }

                    if(i-1>=0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)){
                        ds.unionBySize(p,p1);
                    }
                }
                else if(grid[i][j] == 3){
                    if(j-1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6) ){
                        ds.unionBySize(p,p4);
                    }
                    if(i+1 < n && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6) ){
                        ds.unionBySize(p,p2);
                    }
                }
                else if(grid[i][j] == 4){
                    if(j+1 < m && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5) ){
                        ds.unionBySize(p,p3);
                    }
                    if(i+1 < n && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6) ){
                        ds.unionBySize(p,p2);
                    }
                }
                else if(grid[i][j] == 5){
                    if(i-1>=0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)){
                        ds.unionBySize(p,p1);
                    }
                    if(j-1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6) ){
                        ds.unionBySize(p,p4);
                    }
                }
                else if(grid[i][j] == 6){
                    if(i-1>=0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)){
                        ds.unionBySize(p,p1);
                    }
                    if(j+1 < m && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5) ){
                        ds.unionBySize(p,p3);
                    }
                }
            }
        }
        return ds.findpar(0) == ds.findpar(n*m-1);
