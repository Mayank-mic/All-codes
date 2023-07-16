// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<vector<int>> ans(m, vector<int>(n, 0));

        queue<pair<int, pair<int, int>>> q;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    q.push({0, {i, j}});
                    vis[i][j]=1;
                }
            }
        }

        

        int delr[]={-1, +1, 0, 0};
        int delc[]={0, 0, -1, +1};

        while(!q.empty()){
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            for(int i=0;i<4;++i){
                int adjr = row + delr[i];
                int adjc = col + delc[i];

                if(adjr>=0 && adjr<m && adjc >=0 && adjc<n && vis[adjr][adjc]==0){
                    if(mat[adjr][adjc]==1){
                        q.push({steps+1, {adjr, adjc}});
                        ans[adjr][adjc]=steps+1;
                        vis[adjr][adjc]=1;
                    }
                }
            }
        }
        return ans;
    }
        
};
