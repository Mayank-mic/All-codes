// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.



class Solution {
public:

    void dfs(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, int& temp, int dr[], int dc[]){


        vis[row][col]=1;
        temp+=grid[row][col];


        for(int i=0;i<4;++i){
            int newr = row+dr[i];
            int newc = col+dc[i];

            if(newr>=0 && newc>=0 && newr<n && newc<m && vis[newr][newc]==0 && grid[newr][newc]!=0){
                dfs(newr, newc, n, m, grid, vis, temp, dr, dc);
            }
        }

    }


    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dr[4] = {0, 0, -1, +1};
        int dc[4] = {-1, +1, 0, 0};

        int ans = -1;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int temp =0;
                if(grid[i][j]!=0){
                    dfs(i, j, n, m, grid, vis, temp, dr, dc);
                }
                ans=max(ans, temp);
            }
        }
        return ans;
    }
};
