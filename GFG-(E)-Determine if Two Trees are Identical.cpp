// Given two binary trees, the task is to find if both of them are identical or not. 

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool helper(Node* r1, Node* r2){
        if(r1==NULL && r2==NULL) return true;
        
        if(r1==NULL && r2) return false;
        if(r2==NULL && r1) return false;
        
        if(r1->data!=r2->data) return false;
        
        helper(r1->left, r2->left) && helper(r1->right, r2->right);
    }
    
    
    bool isIdentical(Node *r1, Node *r2)
    {
        return helper(r1, r2);
        
        
        
        
    }
};
