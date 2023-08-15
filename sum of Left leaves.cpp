// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

class Solution {
public:
    void helper(TreeNode* root, int sign, int& sum){
        if(root->left==NULL && root->right==NULL && sign==1){
            sum+=root->val;
        }else if(root->left==NULL && root->right==NULL && sign==-1){
            return;
        }

        if(root->left!=NULL) helper(root->left, 1, sum);
        if(root->right!=NULL) helper(root->right, -1, sum);

    }

    int sumOfLeftLeaves(TreeNode* root) {

        int ans=0;
        if(root->right==NULL && root->left==NULL) return 0;
 
        helper(root, 0, ans);
        return ans;
        
    }
};



/////        Method 2 

class Solution {
   bool isLeafNode(TreeNode* node){
       if(node->left == NULL and node->right == NULL) return true;
       return false;
   }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*>q;
        q.push(root);
        int sumOfLeaves = 0;

        while(!q.empty()){
             int sz = q.size();
             for(int i=0;i<sz;i++){
                 TreeNode* node = q.front();
                 q.pop();

                 if(node->left){
                    if(isLeafNode(node->left)){
                       sumOfLeaves += node->left->val;
                    }
                    q.push(node->left);
                 } 
                 if(node->right) q.push(node->right);

             }
        }
        
        return sumOfLeaves;
    }
};
