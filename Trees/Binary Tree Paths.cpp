// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.



class Solution {
public:

    void helper(TreeNode* head, vector<string>& ans, string temp){

        if(!head) return;

        if(head->left==NULL && head->right==NULL){
            temp+=to_string(head->val);
            ans.push_back(temp);
        }

        temp+=to_string(head->val)+"->";

        helper(head->left, ans, temp);
        helper(head->right, ans, temp);

    }


    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string temp ="";
        helper(root, ans, temp);
        return ans;
        
    }
};
