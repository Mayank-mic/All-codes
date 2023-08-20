// You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

// A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int n=accounts.size();

        int maxi=INT_MIN;

        for(int i=0;i<n;++i){
            int sum=0;
            for(auto it: accounts[i]){
                sum+=it;
            }
            maxi = max(maxi, sum);
        }


        return maxi;
        
    }
};
