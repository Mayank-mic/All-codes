// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.


Method 1:


class Solution {
public:
    Node* connect(Node* root) {
        vector<Node* > q;
        q.push_back(root);


        while(!q.empty()){
            vector<Node* > curr;

            for(auto x:q){
                if(x && x->left) curr.push_back(x->left);
                if(x && x->right) curr.push_back(x->right);
            }

            for(int i=0;i<q.size()-1;++i) q[i]->next = q[i+1];

            swap(q, curr);
        }

        return root;
        
    }
};





Method 2:


class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL) return NULL;

        if(root->left) root->left->next = root->right;

        if(root->right && root->next) root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
        
    }
};





Method 3;





class Solution {
public:
    Node* connect(Node* root) {
        //Initialize pointers
        Node *prev = root, *curr;
        while (prev) {
            curr = prev;
            while (curr && curr->left) { 
                //connects the left subtree of same level with right subtree of that same level 
                curr->left->next = curr->right;
                //connect the rightmost node of a level to the leftmost node of the next level.
                if (curr -> next) curr->right->next = curr->next->left;
                curr = curr->next;
            }
            prev = prev -> left;
        }
        return root;
    }
};







