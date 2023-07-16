// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0]=1;

        queue<pair<int, pair<int, int>>> pq;

        if(grid[0][0]==1) return -1;

        pq.push({1, {0, 0}});


        while(!pq.empty()){

            auto it= pq.front();
            pq.pop();

            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row==n-1 && col==n-1 ) return steps;

            for(int adjr = -1; adjr<=1 ;++adjr){
                for(int adjc =-1; adjc<=1; ++adjc){

                    int newr = row+adjr;
                    int newc = col+adjc;

                    if(newr>=0 && newc>=0 && newr<n && newc<n && vis[newr][newc]==0 && grid[newr][newc]==0){
                        vis[newr][newc]=1;
                        pq.push({steps+1, {newr, newc}});
                    }

                }
            }
        }

        
        return -1;
    }
};
