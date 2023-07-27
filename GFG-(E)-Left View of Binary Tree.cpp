// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
//   The task is to complete the function leftView(), which accepts root of the tree as argument.


void helper(Node* root, int level,vector<int>& ans){
    
    if(root==NULL) return;
    
    if(ans.size()==level) ans.push_back(root->data);
    
    helper(root->left, level+1, ans);
    
    helper(root->right, level+1, ans);
    
}


vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> ans;
   
   helper(root,0,  ans);
   
   return ans;
   
   
   
}
