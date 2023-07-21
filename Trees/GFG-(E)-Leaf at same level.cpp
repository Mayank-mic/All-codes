// Given a Binary Tree, check if all leaves are at same level or not.


  class Solution{
  public:
    /*You are required to complete this method*/
    
    void check(Node* root, int temp, bool &ans){
        
        if(root->left==NULL && root->right==NULL && temp!=1){
            ans=false;
            return;
        }
        
        if(root->left!=NULL) check(root->left, temp-1, ans);
        if(root->right!=NULL) check(root->right, temp-1, ans);
        
        
    }
    
    
    int height(Node* root){
        if(root==NULL) return 0;
        
        int left = 1+height(root->left);
        int right = 1+height(root->right);
        
        return max(left, right);
    }
    
    
    bool check(Node *root)
    {
        //Your code here
        
        bool ans=true;
        
        int max_height= height(root);
        
        check(root, max_height, ans);
        
        return ans;
        
        
    }
};
