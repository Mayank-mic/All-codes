// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
// The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
// The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

// Note: H is the height of the tree and this space is used implicitly for the recursion stack.




class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void helper(Node* root, vector<Node*>&store){
        if(root==NULL) return;
        
        helper(root->left, store);
        store.push_back(root);
        helper(root->right, store);
    }
    
    
    Node * bToDLL(Node *root)
    {

        
        if(root->right==NULL && root->left==NULL) return root;
        
        vector<Node*> temp;
        
        helper(root, temp);
        
        temp[0]->right = temp[1];
        temp[0]->left =NULL;
        
        for(int i=1;i<temp.size()-1;++i){
            
            temp[i]->left =temp[i-1];
            temp[i]->right=temp[i+1];
            
        }
        
        temp[temp.size()-1]->left =temp[temp.size()-2];
        temp[temp.size()-1]->right = NULL;
        
        return temp[0];
        
    }
};
