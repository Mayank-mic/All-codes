// Given a sorted array A[] of size N, delete all the duplicated elements from A[]. 
// Modify the array such that if there are X distinct elements in it then the first X positions of 
// the array should be filled with them in increasing order and return the number of distinct elements in the array.

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        
        if(n==1) return 1;
        
        int i=0;
        int j=1;
        
        int p=0;
        
        int counter=1;
        while(j!=n){
            
            while(a[j]==a[i]){
                j++;
                if(j==n) break;
            }
            
            if(j==n) break;
            
            counter++;
            ++i;
            a[i]=a[j];
            j++;
        }
        
        return counter;
        
        
    }
};
