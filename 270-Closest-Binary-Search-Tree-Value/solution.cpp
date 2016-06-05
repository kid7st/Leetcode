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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while(root != NULL){
            if( abs(res - target) > abs(root->val - target) ){
                res = root->val;
            }
            
            if(root->val > target){
                root = root->left;   
            }else if(root->val < target){
                root = root->right;
            }else{
                return res;
            }
        }
        return res;
    }
};