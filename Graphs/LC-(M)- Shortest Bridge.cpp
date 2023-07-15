// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1




class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int row=-1;
        int col=-1;

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                    vis[row][col]=1;
                    break;
                }
            }
            if(row!=-1) break;
        }

        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0, +1, -1};

        queue<pair<int, int>> q;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {row, col}});
        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int ind=0; ind<4;++ind){
                int newr = r +delr[ind];
                int newc = c+ delc[ind];

                if(newr>=0 && newc >=0 && newr<n && newc<n&& grid[newr][newc]==1 && vis[newr][newc]==0){
                    vis[newr][newc]=1;
                    q.push({newr, newc});
                    pq.push({0, {newr, newc}});
                }

            }
        }


        while(!pq.empty()){
            auto curr = pq.front();
            int steps = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            pq.pop();

            for(int ind=0; ind<4;++ind){
                int newr = r + delr[ind];
                int newc = c + delc[ind];

                if(newr>=0 && newc>=0 && newr<n && newc <n){        

                if(grid[newr][newc]==0 && vis[newr][newc]==0){
                    vis[newr][newc]=1;
                    pq.push({steps+1, {newr, newc}});
                }

                if(grid[newr][newc]==1 && vis[newr][newc]==0) return steps;
                else if(grid[newr][newc]==1 && vis[newr][newc]==1) vis[newr][newc]=2;
            }

            }
        }

        return -1;
    }
};
