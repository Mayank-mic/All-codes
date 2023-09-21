// // Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. 
// Your task is to count the frequency of all elements from 1 to N.
// // Note: The elements greater than N in the array can be ignored for counting and do modify the array in-place.


void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        
        int freq[max(N, P)];
        
        memset(freq, 0, sizeof(freq));
        
        
        for(auto it: arr){
            freq[it-1]++;
        }
        
        for(int i=0;i<N;++i){
            arr[i]=freq[i];
        }
        
    }
