// Union of two arrays can be defined as the common and distinct elements in the two arrays.
// Given two sorted arrays of size n and m respectively, find their union.



vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        
        vector<int> ans;
        
        
        int i=0;
        int j=0;
        
        while(i!=n && j!=m){
            if(arr1[i]==arr2[j]){
                if(ans.empty()) ans.push_back(arr1[i]);
                else if(ans.back()!=arr1[i]) ans.push_back(arr1[i]);
                ++i;
                ++j;
            }else if(arr1[i]<arr2[j]){
                if(ans.empty()) ans.push_back(arr1[i]);
                else if(ans.back()!=arr1[i]) ans.push_back(arr1[i]);
                ++i;
            }else{
                if(ans.empty()) ans.push_back(arr2[j]);
                else if(ans.back()!=arr2[j]) ans.push_back(arr2[j]);
                ++j;
            }
        }
        
        if(i==n){
            while(j!=m){
                if(ans.back()!=arr2[j]) ans.push_back(arr2[j]);
                j++;
            }
        }else{
            while(i!=n){
                if(ans.back()!=arr1[i]) ans.push_back(arr1[i]);
                i++;
            }
        }
        
        return ans;
    }
