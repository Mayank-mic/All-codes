
// Given a 2D grid consists of 0s (land) and 1s (water).  
// An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.





class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int row, int col, int delr[], int delc[]){

        vis[row][col]=1;

        for(int i=0;i<4;++i){
            int newr = row+ delr[i];
            int newc = col +delc[i];

            if(newr>=0 && newc>=0 && newr<m && newc<n && vis[newr][newc]==0 && grid[newr][newc]==0){
                dfs(grid, vis, n, m, newr, newc, delr, delc);
            }
        }

    }


    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n= grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0, -1, +1};

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j]==0 && grid[i][j]==0 && (i==0 || j==0 || i==m-1 || j==n-1)){
                    dfs(grid, vis, n, m, i, j, delr, delc);
                }
            }
        }

        int counter=0;

        for(int i=0;i<m;++i){
            for(int j=0; j<n;++j){
                if(vis[i][j]==0 && grid[i][j]==0){
                    dfs(grid, vis, n, m, i, j, delr, delc);
                    counter++;
                }
            }
        }

        return counter;
    }
};
