// Given a Binary Search Tree. The task is to find the minimum valued element in this given BST.


int minValue(Node* root) {
    
    if(root==NULL) return -1;
    
    // Code here
    if(root->left==NULL) return root->data;
    
    return minValue(root->left);
}
