// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.



class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        

        int sum =0;

        int n= mat.size();
        int m = mat[0].size();

        int i=0;
        int j = 0;

        while(i<n && j<m){
            sum+=mat[i][j];
            i++;
            j++;
        }

        i = 0;
        j = m-1;


        while(i<n && j>=0){
            sum+=mat[i][j];
            i++;
            j--;
        }

    

        if(n%2!=0) sum-= mat[n/2][n/2];

        return sum;

    }
};
