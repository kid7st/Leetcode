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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int depth = 0;
        return depthTree(root, depth);
            
    }
    
private:
    bool depthTree(TreeNode* root, int &depth){
        if(root == NULL){
            depth = 0;
            return true;
        }
        
        int depthLeft, depthRight;
        bool res = depthTree(root->left, depthLeft) && depthTree(root->right, depthRight);
        depth = max(depthLeft, depthRight) + 1;
        return res && abs(depthLeft - depthRight) <= 1;
    }
};