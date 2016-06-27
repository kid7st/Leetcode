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
    int minDepth(TreeNode* root) {
        int res = INT_MAX;
        if(!root) return 0;
        dfs(root, res, 1);
        return res;
    }
    
    void dfs(TreeNode* root, int &minDepth, int depth){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            minDepth = min(minDepth, depth);
            return;
        }
        
        if(depth <= minDepth){
            dfs(root->left, minDepth, depth + 1);
            dfs(root->right, minDepth, depth + 1);
        }
        return;
    }
};