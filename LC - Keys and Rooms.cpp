// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
// Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and 
// you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.




class Solution {

void dfs(int node, vector<vector<int>>& rooms, int vis[]){
    vis[node]=1;

    for(auto it: rooms[node]){
        if(!vis[it]){
            dfs(it, rooms, vis);
        }
    }
    
}


public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        
        int vis[n];
        memset(vis, 0, sizeof(vis));

        dfs(0, rooms, vis);

        for(int i=0;i<n;++i){
            if(vis[i]==0) return false;
        }

        return true;
    }
};
