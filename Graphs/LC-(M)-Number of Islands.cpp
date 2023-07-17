// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
//   You may assume all four edges of the grid are all surrounded by water.


class Solution {
public:
    

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m, int row, int col, int delr[], int delc[]){
        
        vis[row][col]=1;

        for(int ind=0;ind<4;++ind){
            int newr = row+delr[ind];
            int newc = col+delc[ind];
            
            if(newr>=0 && newc>=0 && newr<m && newc<n && grid[newr][newc]=='1'&& vis[newr][newc]==0){
                dfs(grid, vis, n, m, newr, newc, delr, delc);
            }

        }

    }


    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n= grid[0].size();


        vector<vector<int>> vis(m, vector<int>(n,0));

        int count=0;

        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0, -1, +1};
        

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(grid, vis, n, m, i, j, delr, delc);
                    count++;
                }
            }
        }

        return count;


    }
};
