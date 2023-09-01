
class dsu{


    public:
    vector<int> parent;
    vector<int> size;

    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);


        for(int i=0;i<=n;++i){
            parent[i]=i;
        }
    }


    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }


    void ubs(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v == ulp_u) return;
        else if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

    }
};
