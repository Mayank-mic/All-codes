// You are given an array of strings equations that represent relationships between variables where each string equations[i] 
// is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters 
// (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.



class Solution {
public:

    class dsu{
        public:
        vector<int> parent;
        vector<int> size;

        dsu(int n){
            parent.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i=0;i<n+1; ++i){
                parent[i]=i;
            }
        }

        int findpar(int node){
            if(node==parent[node]) return node;
            return parent[node] = findpar(parent[node]);
        }


        void ubs(int u, int v){
            int ulp_u=findpar(u);
            int ulp_v=findpar(v);

            if(ulp_v==ulp_u) return;
            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]=ulp_v;
            }else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
        }

    };

    static bool comp(string a, string b){
        if(a[1]=='=' && b[1]=='!') return true;

       return false;
    }


    bool equationsPossible(vector<string>& equations) {
        
        int n=equations.size();

        dsu ds(25);

        sort(equations.begin(), equations.end(), comp);

            for(int i=0;i<n;++i){

                int first = equations[i][0]-'a';
                int sec = equations[i][3]-'a';

                if(equations[i][1]=='='){
                    ds.ubs(first, sec);
                }else{
                    if(ds.findpar(first)== ds.findpar(sec)) return false;
                }

            }

            return true;
        }

        

};
