// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int row, int col, int delr[], int delc[]){
            vis[row][col]=1;

            for(int i=0;i<4;++i){
                int newr = row+ delr[i];
                int newc = col+ delc[i];

                if(newr>=0 && newc>=0 && newr<m && newc<n && vis[newr][newc]==0 && grid[newr][newc]==1){
                    dfs(grid, vis, n, m, newr, newc, delr, delc);
                }
            }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));

        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0, -1, +1};

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j]==0 &&(i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    dfs(grid, vis, n, m, i, j, delr, delc);
                }
            }
        }

        int counter=0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j]==0 && grid[i][j]==1)
                counter++;
            }
        }

        return counter;
    }
};
