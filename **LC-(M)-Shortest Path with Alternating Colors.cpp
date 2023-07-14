// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. 
// Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:

// redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 
// to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> vis(n, vector<int>(2, 0));

        vector<int> dist(n, INT_MAX);

        vector<pair<int, int>> adj[n];

        for(auto it: redEdges){
            adj[it[0]].push_back({it[1], 0});
        }

        for(auto it: blueEdges){
            adj[it[0]].push_back({it[1], 1});
        }

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {0, -1}});

        vis[0][0]=1;
        vis[0][1]=1;

        dist[0]=0;

        while(!q.empty()){
            auto curr = q.front();
            int node = curr.first;
            int steps = curr.second.first;
            int color = curr.second.second;
           
            q.pop();

            for(auto it: adj[node]){
                
                if(it.second!=color && vis[it.first][it.second]==0){
                    vis[it.first][it.second]=1;
                    dist[it.first] = min(dist[it.first], steps+1);
                    
                    q.push({it.first, {steps+1, it.second}});
                }
            }


        }

        for(int i=0;i<n;++i){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }


        return dist;
    }
};
