// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
// You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.



class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int row, int col){

        vis[row][col]=1;
        int ans=0;
        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0, -1, +1};

        for(int i=0;i<4;++i){
            int newr = row+delr[i];
            int newc = col+delc[i];

            if(newr>=0 && newc>=0 && newr<m && newc<n && vis[newr][newc]==0 && grid[newr][newc]==1){
                ans+=dfs(grid, vis, n, m, newr, newc);
            }
        }
        return 1+ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans=0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j]==0 && grid[i][j]==1 ){
                    ans=max(ans, dfs(grid, vis, n, m, i, j));
                }
            }
        }

        return ans;
    }
};
