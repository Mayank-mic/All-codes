// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i = n - 1;
            int j = 0;
            while (i >= 0 && j < m) {
                if (arr1[i] >= arr2[j]) {
                    swap(arr1[i], arr2[j]);
                    i--;
                    j++;
                } else {
                    break;
                }
            }        
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        }
};
