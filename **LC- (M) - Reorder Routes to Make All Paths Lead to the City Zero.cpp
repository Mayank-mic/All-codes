// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities 
// (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.


class Solution {
public:
    int count=0;

    void dfs(vector<pair<int, int>> adj[], int node, int par){


        for(auto it: adj[node]){
            if(it.first != par){
                count+=it.second;
                dfs(adj, it.first, node);
            }
        }

    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];

        for(auto it: connections){
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }

        dfs(adj, 0, -1);

        return count;
    }
};
