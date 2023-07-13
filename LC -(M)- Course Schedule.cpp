// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// // Return true if you can finish all courses. Otherwise, return false.


// Example:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.


class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        
         
	    int indeg[N];

	    memset(indeg, 0, sizeof(indeg));
	    
			int m= prerequisites.size();
	    
	    for(int i=0;i<m;++i){
	        indeg[prerequisites[i][0]]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<N;++i){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    int cnt=0;
	    
	    while(!q.empty()){
	        int node= q.front();
	        q.pop();
	        cnt++;
	        

	        for(int i=0;i<m;++i){
	            if(prerequisites[i][1]==node){
	                indeg[prerequisites[i][0]]--;
	            
	            if(indeg[prerequisites[i][0]]==0){
	                q.push(prerequisites[i][0]);
	            }
	        }
				}


	    }
	    
	    return cnt==N;

    }

};
