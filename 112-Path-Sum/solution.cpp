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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        
        bool res = false;
        dfs(root, 0, sum, res);
        return res;
    }
    
    void dfs(TreeNode* root, int current, int sum, bool &flag){
        if(root->left == NULL && root->right == NULL){
            if(current + root->val == sum) flag = true;
            return;
        }
        if(flag) return;
        
        if(root->left) dfs(root->left, current + root->val, sum, flag);
        if(root->right) dfs(root->right, current + root->val, sum, flag);
        return;
    }
};