// Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, and a number X is given. 
//   The task is to find whether element X is present in the matrix or not.

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	   // int start=0;
	   // for(int i=0;i<N;++i){
	   //     if(X>=mat[i][0] && X<=mat[i][M-1]){
	   //         start=i;
	   //         for(int i=0;i<M;++i){
	   //     if(mat[start][i]==X) return 1;
	   // }
	   // }
	   // }
	   // return 0;
	   
	   
	   int start = 0;
        int end = M-1;
        
        while(start<N && end>=0){
            
            
            if(mat[start][end] < X){
                start++;
            }else if(mat[start][end] > X){
                
                end--;
            }else{
                return 1;
            }
            
            
        }
        
        return 0;
	    
	    
	}
};
