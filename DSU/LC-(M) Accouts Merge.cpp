// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
// and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person 
// if there is some common email to both accounts. Note that even if two accounts have the same name, 
// they may belong to different people as people could have the same name. A person can have any number of accounts initially,
// but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name,
// and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.






class Solution {
public:


    class dsu{

    public:

        vector<int> parent, size;
        
        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i=0;i<n+1;++i){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node==parent[node]) return node;
            else return parent[node]=findUPar(parent[node]);
        }


        void ubs(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u==ulp_v) return;
            if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }

        }


    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n= accounts.size();

        unordered_map<string, int> mapMailNode;
        dsu ds(n);

        for(int i=0;i<n;++i){
            for(int j=1;j<accounts[i].size(); ++j){
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail]=i;
                }else{
                    ds.ubs(mapMailNode[mail], i);
                }

            }
        }


        vector<string> mergedMail[n];

        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;++i){
            if(mergedMail[i].size()==0) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;


    }
};
