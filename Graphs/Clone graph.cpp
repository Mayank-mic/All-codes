// Given a reference of a node in a connected undirected graph. Return a clone of the graph.
// Each node in the graph contains a value (Integer) and a list (List[Node]) of its neighbors.



class Solution {
public:
    Node* vis[101] = {NULL};
    
    Node* cloneGraph(Node* node) {
        Node* temp = new Node(node->val);
        
        temp->val = node->val;
        vis[node->val] = temp;
        
        for(auto it: node->neighbors){
            if(!vis[it->val]) cloneGraph(it);
            temp->neighbors.push_back(vis[it->val]);
        }
        
        return temp;
    }
};
