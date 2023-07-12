class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(int j: graph[i]) {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr: adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
