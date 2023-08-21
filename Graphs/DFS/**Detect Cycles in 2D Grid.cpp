// Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

// A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

// Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

// Return true if any cycle of the same value exists in grid, otherwise, return false.




class Solution {
public:

    bool dfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis, char target, int parent, int dr[], int dc[]){

        vis[row][col]=1;

        bool report=false;

        for(int i=0;i<4;++i){
            int newr = row +dr[i];
            int newc = col +dc[i];

            if(newr>=0 && newc >=0 && newr<n && newc <m && grid[newr][newc]==target){
                if(vis[newr][newc]==1 && newr*n+(newc+1)!=parent) return true;

                if(vis[newr][newc]==0 && newr*n+(newc+1)!=parent){
                    report=report|dfs(newr, newc, n, m, grid, vis, target, row*n+(col+1), dr, dc);
                } 
            }

        }

        return report;
    }


    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int dr[4] = {0, 0, -1, +1};
        int dc[4] = {-1, +1, 0, 0};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        bool report = false;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0){
                    report = report | dfs(i, j, n, m, grid, vis, grid[i][j], i*n+(j+1), dr, dc);
                }
                
            }
        }      

        return report;
    }
};
