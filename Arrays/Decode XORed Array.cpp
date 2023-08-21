// There is a hidden integer array arr that consists of n non-negative integers.

// It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

// You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

// Return the original array arr. It can be proved that the answer exists and is unique.



class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {

        int n= encoded.size();

        vector<int> ans(n+1, 0);
        ans[0] = first;

        for(int i=1;i<n+1;++i){
            ans[i]= ans[i-1]^encoded[i-1];
        }

        return ans;
        
    }
};
