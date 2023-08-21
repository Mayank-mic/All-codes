// You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.

// You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.





class Solution {
public:


    bool dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis){

        if(i<0 || j<0 || i>=n || j>=m) return false;

        if(i==n-1 && j==m-1) return true;

        vis[i][j]= 1;

        bool reached = false;

        if(grid[i][j]==1){
            if(j+1<m && vis[i][j+1]==0 && (grid[i][j+1]==3 || grid[i][j+1]==5 || grid[i][j+1]==1)){
                reached = dfs(i, j+1, n, m, grid, vis);
            }

            if(j-1>=0 && vis[i][j-1]==0 && (grid[i][j-1]==4 || grid[i][j-1]==6 || grid[i][j-1]==1)){
                reached = reached| dfs(i, j-1, n, m, grid, vis);
            }
        }
        else if(grid[i][j]==2){
            if(i+1<n && vis[i+1][j]==0 && (grid[i+1][j]==5 || grid[i+1][j]==6 || grid[i+1][j]==2)){
                reached = dfs(i+1, j, n, m, grid, vis);
            }

            if(i-1>=0 && vis[i-1][j]==0 && (grid[i-1][j]==3 || grid[i-1][j]==4 || grid[i-1][j]==2)){
                reached = reached| dfs(i-1, j, n, m, grid, vis);
            }
        }
        else if(grid[i][j]==3){
            if(i+1<n && vis[i+1][j]==0 && (grid[i+1][j]==2 || grid[i+1][j]==6 || grid[i+1][j]==5)){
                reached = dfs(i+1, j, n, m, grid, vis);
            }

            if(j-1>=0 && vis[i][j-1]==0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6)){
                reached = reached| dfs(i, j-1, n, m, grid, vis);
            }
        } else if(grid[i][j]==4){
            if(i+1<n && vis[i+1][j]==0 && (grid[i+1][j]==2 || grid[i+1][j]==6 || grid[i+1][j]==5)){
                reached = dfs(i+1, j, n, m, grid, vis);
            }

            if(j+1<m && vis[i][j+1]==0 && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5)){
                reached = reached| dfs(i, j+1, n, m, grid, vis);
            }
        } else if(grid[i][j]==5){
            if(i-1>=0 && vis[i-1][j]==0 && (grid[i-1][j]==3 || grid[i-1][j]==2 || grid[i-1][j]==4)){
                reached = dfs(i-1, j, n, m, grid, vis);
            }

            if(j-1>=0 && vis[i][j-1]==0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6)){
                reached = reached| dfs(i, j-1, n, m, grid, vis);
            }
        }else if(grid[i][j]==6){
            if(i-1>=0 && vis[i-1][j]==0 && (grid[i-1][j]==4 || grid[i-1][j]==2 || grid[i-1][j]==3)){
                reached = dfs(i-1, j, n, m, grid, vis);
            }

            if(j+1<m && vis[i][j+1]==0 && (grid[i][j+1]==1 || grid[i][j+1]==5 || grid[i][j+1]==3)){
                reached = reached| dfs(i, j+1, n, m, grid, vis);
            }
        }



        return reached;
    }


    bool hasValidPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        return dfs(0, 0, n, m , grid, vis);
        
    }
};
