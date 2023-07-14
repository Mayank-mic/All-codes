// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


class Solution {
public:

    vector<vector<int>> ans;

    void dfs(int node, int n, vector<vector<int>>& graph, vector<int> temp){

            temp.push_back(node);
            
            if(node == n-1){
                ans.push_back(temp);
            }

            for(auto it: graph[node]){
                dfs(it, n, graph, temp);
            }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> temp;

        dfs(0, n, graph, temp);

        return ans;
    }
};
