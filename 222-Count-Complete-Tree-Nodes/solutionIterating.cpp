/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /* Iterating Solution */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        while(root != NULL){
            int leftHeight = treeHeight(root->left);
            int rightHeight = treeHeight(root->right);
        
            if(leftHeight > rightHeight){
                count += pow(2, rightHeight);
                root = root->left;
            }else{
                count += pow(2, leftHeight);
                root = root->right;
            }
        }
        return count;
    }

private:
    int treeHeight(TreeNode* root){
        int count = 0;
        while(root != NULL){
            count += 1;
            root = root->left;
        }
        
        return count;
    }
};