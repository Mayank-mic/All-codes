// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void helper(Node* root, int level, vector<int> &ans){
        if(root==NULL) return;
        
        if(ans.size()==level) ans.push_back(root->data);
        
        helper(root->right, level+1, ans);
        helper(root->left, level+1, ans);
        
    }
    
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       
       helper(root, 0, ans);
       
       return ans;
    }
};
