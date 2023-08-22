// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell 
// there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server.


class Solution {
public:
    class dsu{
        public: 
        vector<int> parent;
        vector<int> size;

        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i=0;i<=n;++i){
                parent[i]=i;
            }
        }


        int findUPar(int node){
            if(parent[node]==node) return node;

            return parent[node]= findUPar(parent[node]);
        }

        void ubs(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;
            else if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
                size[ulp_u]=0;
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
                size[ulp_v]=0;
            }
        }

    };


    int countServers(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m = grid[0].size();


        dsu ds(n*m);

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                int cellIndex = i*m + j+1;

                while(j<m){
                    if(grid[i][j]==1){
                        int neighCellInd = i*m+j+1;

                        ds.ubs(cellIndex, neighCellInd);
                        }
                        j++;
                    }

                }
            }
        }


        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                if(grid[i][j]==1){
                    int cellIndex = i*m + j+1;

                while(i<n){
                    if(grid[i][j]==1){
                        int neighCellInd = i*m+j+1;

                        ds.ubs(cellIndex, neighCellInd);
                    }
                    i++;
                }

                }

                
            }
        }


        int counter=0;

        for(int i=0;i<=n*m;++i){
            cout<<ds.size[i]<<" ";
            if(ds.size[i]>1){
                counter+=ds.size[i];
            }
        }


        return counter;



    }
};
