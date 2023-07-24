// Eulerian Path is a path in graph that visits every edge exactly once. 
// Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
// The task is to find that there exists the Euler Path or circuit or none in given undirected graph with V vertices and adjacency list adj.

    void dfs(int V, vector<int> adj[], vector<int>& visited, int node){
        visited[node]=1;
        
        for(auto it: adj[node]){
            if(visited[it]!=1){
            dfs(V, adj, visited, it);
            }
        }
    }

	int isEularCircuit(int V, vector<int>adj[]){

	    vector<int> total_deg(V, 0);
	    vector<int> visited(V, 0);
	    
	    
	    for(int i=0;i<V;++i){
	        total_deg[i]= adj[i].size();
	    }
	    
	    
	    for(int i=0;i<V;++i){
	        if(total_deg[i]>0){
	            dfs(V, adj, visited, i);
	            break;
	        }
	    }
	    
	    
	    for(int i=0;i<V;++i){
	        if(total_deg[i]>0 && visited[i]==0){
	            return 0;
	        }
	    }
	    
	    int counter=0;
	    
	    for(int i=0;i<V;++i){
	        if(total_deg[i]%2!=0) counter++;
	    }
	    
	    if(counter==0) return 2;
	    
	    if(counter==2) return 1;
	    
	    return 0;
	    
	    
	}






// ???????//////////?????????///////////???????????////////////////&&&&&&&&


int isEularCircuit(int V, vector<int>adj[]){
	    
	    int counter=0;
	    
	    
	    for(int i=0;i<V;++i){
	        if(adj[i].size()%2!=0) counter++;
	    }
	    
	    if(counter==0) return 2;
	    
	    if(counter==2) return 1;
	    
	    return 0;
	    
	}
