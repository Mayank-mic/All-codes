// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.


class Solution {
public:

    static bool comp(pair<int, int>a, pair<int, int> b){
         if(a.second<b.second){
             return true;
         }
        if(a.second==b.second) return a.first<b.first;
        return false;
    }



    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {


        vector<pair<int, int>> store;

        vector<int> ans;

        int ind =0;

        for(auto it: mat){
            int temp =0;
            for(auto p : it){
                if(p==1) temp++;
            }
            store.push_back(make_pair(ind, temp));
            ind++;
        }

        sort(store.begin(), store.end(), comp);

        int i=0;

        while(k--){
            ans.push_back(store[i].first);
            i++;
        }

     //   for(auto it: store) cout<<it.first<<" "<<it.second<<endl;

        return ans;
        
    }
};
