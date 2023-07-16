// Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
// When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

// Notice that you can not jump outside of the array at any time.




///////// BFS


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();

        vector<int> vis(n, 0);

        queue<int> q;
        vis[start]=1;

         if(arr[start]==0) return true;

        q.push(start);

        while(!q.empty()){
            int index = q.front();
            q.pop();

           

            if(index+arr[index]<n && index+arr[index]>=0 && vis[index+arr[index]]==0){
                    vis[index+arr[index]]=1;
                    q.push(index+arr[index]);
                    if(arr[index+arr[index]]==0) return true;
            }
            if(index-arr[index]<n && index-arr[index]>=0 && vis[index-arr[index]]==0){
                    q.push(index-arr[index]);
                    vis[index-arr[index]]=1;
                     if(arr[index-arr[index]]==0) return true;
            }
            
        }

        return false;

    }
};







////////// DFS 

class Solution {
    bool dfs(int i, int n, vector<int> &arr, vector<int> &vis) {
        vis[i] = 1;
        if(!arr[i]) return true;

        if(i + arr[i] < n && !vis[i + arr[i]]) {
            if(dfs(i + arr[i], n, arr, vis)) return true;
        }
        if(i - arr[i] >= 0 && !vis[i - arr[i]]) {
            if(dfs(i - arr[i], n, arr, vis)) return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n);
        return dfs(start, n, arr, vis);
    }
};
