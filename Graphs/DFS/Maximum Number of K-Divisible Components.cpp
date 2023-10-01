// There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, 
// where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

// A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, 
// where the value of a connected component is the sum of the values of its nodes.

// Return the maximum number of components in any valid split.


class Solution {
public:

    long long dfs(int& ans, vector<int>& values, int node, int prevNode, vector<int> adj[], int k){

        long long sum = values[node];
        for(auto it: adj[node]){
            if(it==prevNode) continue;
            sum+=dfs(ans, values, it, node, adj, k);
        }

        if(sum%k==0){
            ans++;
            return 0;
        }
        else return (long long)sum;

    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<int> adj[n];

        for(int i=0;i<edges.size();++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt=0;
        dfs(cnt, values, 0, -1, adj, k);
        return cnt;
        
    }
};
