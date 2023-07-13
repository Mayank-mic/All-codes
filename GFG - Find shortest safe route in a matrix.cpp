// Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), 
// calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. 
// We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.


class Solution
{
    
    bool isValid(int n, int m, int row, int col){
        
        if(row>=0 && row<n && col>=0 && col<m){
            return true;
        }
        return false;
        
    }
    
    
    
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       
       int n=mat.size();
       int m=mat[0].size();
       
       int delr[]={-1, 0, +1, 0};
       int delc[]={0, -1, 0, +1};
       
       queue<pair<int, int>> q;
       
       
       for(int i=0;i<n;++i){
           for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    q.push({i, j});
                }
           }
       }
       
       
       while(!q.empty()){
           auto curr = q.front();
           int row = curr.first;
           int col = curr.second;
           q.pop();
           
           for(int i=0;i<4;++i){
               int newr = row+delr[i];
               int newc = col+delc[i];
               
               if(isValid(n, m, newr, newc)){
                   mat[newr][newc]=0;
               }
           }
       }
      
        vector<vector<int>> vis(n, vector<int>(m, 0));
       
        queue<pair<int, pair<int, int>>> pq;
       
        for(int i=0;i<n;++i){
            if(mat[i][0]==1) {
            pq.push({1, {i, 0}});
            vis[i][0]=1;
            } 
        }
       
        int del_r[]={-1, +1, 0};
        int del_c[]={0, 0, +1};
       
        while(!pq.empty()){
            auto it= pq.front();
            int steps=it.first;
            int row = it.second.first;
            int col = it.second.second;
           
            if(col==m-1) return steps;
           
            pq.pop();
           
            for(int ind=0;ind<4;++ind){
                int newr = row+del_r[ind];
                int newc = col+del_c[ind];
               
                if(isValid(n, m, newr, newc) && vis[newr][newc]!=1){
                    if(mat[newr][newc]==1) pq.push({steps+1,{newr, newc}});
                    vis[newr][newc]=1;
                }
            }  
        }
       return -1;
    }
    
};
