/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root, res);
        
        return res;
    }
    
    void inorderTraversal(TreeNode* node, vector<int>& acc){
        if(node == NULL)
            return;
        
        inorderTraversal(node->left, acc);
        acc.push_back(node->val);
        inorderTraversal(node->right, acc);
        
        return;
    }
};