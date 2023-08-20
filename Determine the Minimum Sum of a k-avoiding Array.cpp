// You are given two integers, n and k.

// An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.

// Return the minimum possible sum of a k-avoiding array of length n.


class Solution {
public:
    int minimumSum(int n, int k) {
        
        unordered_set<int> st;

        int ans=0;

        for(int i=1;st.size()<n;++i){
            if(st.find(k-i)==st.end()){
                st.insert(i);
                ans+=i;
            }
        }
        

        return ans;
        
        
    }
};
