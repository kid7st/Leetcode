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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        
        if(leftHeight > rightHeight){
            return countNodes(root->left) + pow(2, rightHeight);
        }else{
            return pow(2, leftHeight) + countNodes(root->right);
        }
        
        return 0;
    }

private:
    int treeHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return treeHeight(root->left) + 1;
    }
};