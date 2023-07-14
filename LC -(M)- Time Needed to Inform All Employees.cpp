// A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

// Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. 
//   Also, it is guaranteed that the subordination relationships have a tree structure.

// The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, 
//   and they will inform their subordinates, and so on until all employees know about the urgent news.

// The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., 
// After informTime[i] minutes, all his direct subordinates can start spreading the news).

// Return the number of minutes needed to inform all the employees about the urgent news.

// Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
// Output: 1
// Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
// The tree structure of the employees in the company is shown.





class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> timetaken(n, 0);

        vector<int> adj[n];

        for(int i=0; i<n;++i){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }


        queue<int> q;

        q.push(headID);

        timetaken[headID]=informTime[headID];

        int maxi=0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                timetaken[it]=timetaken[node]+informTime[it];
                maxi = max(maxi, timetaken[it]);
                q.push(it);
            }
        }

        return maxi;

    }
};


// class Solution {
// public:
//     int dfs(int n,vector<pair<int,int>>adj[],vector<bool>&vis,vector<int>& informTime)
//     {
//         int ans=0;
//         for(auto i:adj[n])
//         {
//             ans=max(ans,informTime[n]+dfs(i.first,adj,vis,informTime));
//         }
//         return ans;
//     }
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
//         vector<pair<int,int>>adj[n];
//         for(int i=0;i<n;i++)
//         {   
//             if(manager[i]!=-1)
//                 adj[manager[i]].push_back({i,informTime[i]});
//         }
//         vector<bool>vis(n,0);
//         int ans=dfs(headID,adj,vis,informTime);
//         return ans;
//     }
// };
