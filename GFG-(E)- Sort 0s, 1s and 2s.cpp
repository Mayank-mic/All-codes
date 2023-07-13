// Given an array of consisting of 0s, 1s, and 2s. Sort them in non decreasing order.

// Dutch National Flag.
// Here low points to the zeroes.
// mid points to the ones.
// while high points to the twos.

class Solution
{
    public:
    void sort012(int a[], int n)
    {

        int low = 0;
        int high = n-1;
        int mid=0;
        
        
        while(mid<=high){
            
            if(a[mid]==0){
                swap(a[mid], a[low]);
                low++;
                mid++;
            }else if(a[mid]==2){
                swap(a[mid], a[high]);
                high--;
            }else{
                mid++;
            }
        }
    }
    
};
