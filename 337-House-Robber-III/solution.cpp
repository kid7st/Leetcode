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
    int rob(TreeNode* root) {
        if(dfsRob(root, true) > dfsRob(root, false)){
            return dfsRob(root, true);
        }else{
            return dfsRob(root, false);
        }
    }
   
private:
    int dfsRob(TreeNode* root, bool robbed) {
        if(root == NULL)
            return 0;
            
        if(robbed){
            return root->val + dfsRob(root->left, false) + dfsRob(root->right, false);
        }else{
            return max(dfsRob(root->left, true), dfsRob(root->left, false)) + 
                        max(dfsRob(root->right, true), dfsRob(root->right, false));
        }
    }
};