// Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

// A grandparent of a node is the parent of its parent if it exists.



DFS////////


class Solution {
public:

    void fns(TreeNode* node, int& max_sum){
        if(node==NULL) return ;

        if(node->val%2==0){


            if(node->left){
                if(node->left->left) max_sum+=node->left->left->val;
                if(node->left->right) max_sum+=node->left->right->val;
            }

            if(node->right){
                if(node->right->left) max_sum+=node->right->left->val;
                if(node->right->right) max_sum+=node->right->right->val;
            }

        }

        fns(node->left, max_sum);
        fns(node->right, max_sum);

    }



    int sumEvenGrandparent(TreeNode* root) {

        int temp =0;

        fns(root, temp);

        return temp;


    }
};







//////BFS


class Solution {
public:

    int fns(TreeNode* node){
        if(node==NULL) return 0;
        int sum = 0;

        if(node->val%2==1) return 0;

        if(node->left){
            if(node->left->left) sum+=node->left->left->val;
            if(node->left->right) sum+=node->left->right->val;
        }

        if(node->right){
            if(node->right->left) sum+=node->right->left->val;
            if(node->right->right) sum+=node->right->right->val;
        }
        
        return sum;

    }



    int sumEvenGrandparent(TreeNode* root) {
        
        queue<TreeNode* > q;
        q.push(root);

        int temp =0;

        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();

            temp+=fns(n);

            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }


        return temp;


    }
};
