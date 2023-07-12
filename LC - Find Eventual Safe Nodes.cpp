// There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
// The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, 
// meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. 
// A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

class Solution {

    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, int pathVis[]){

        vis[node]=1;
        pathVis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis)==true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();

        vector<int> vis(V, 0);
        int pathVis[V];
        memset(pathVis, 0, sizeof(pathVis));
        
        vector<int> safeNodes;

        for(int i=0;i<V;++i){
            if(!vis[i]){
                dfsCheck(i, graph, vis, pathVis);
            }
        }

        for(int i=0;i<V;++i){
            if(pathVis[i]==0) safeNodes.push_back(i);
        }

        return safeNodes;


    }
};
