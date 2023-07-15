// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') 
// and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] 
// denotes the row and column of the cell you are initially standing at.

// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, 
// and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. 
// An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n= maze.size();
        int m= maze[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {entrance[0], entrance[1]}});

        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0 , -1, +1};

        vis[entrance[0]][entrance[1]]=1;

        while(!q.empty()){
            auto node = q.front();
            int steps = node.first;
            int row = node.second.first;
            int col = node.second.second;

            q.pop();
  
            for(int ind = 0; ind<4; ++ind){
                int adjrow = row+ delr[ind];
                int adjcol = col+ delc[ind];

                if(adjrow>=0 && adjcol >=0 && adjrow<n && adjcol<m && 
                maze[adjrow][adjcol]=='.' && vis[adjrow][adjcol]!=1){
                    vis[adjrow][adjcol]=1;            //////////////////////////////       important where to use vis has importance if used before pop gives TLE.
                    q.push({steps+1, {adjrow, adjcol}});
                    if(adjrow==0 || adjcol==0 || adjrow==n-1 || adjcol==m-1) return steps+1;

                }
            }
        }
        
        return -1;

    }
};
