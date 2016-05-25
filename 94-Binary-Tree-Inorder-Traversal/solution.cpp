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
        
        TreeNode* cur = root, *prev = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
            }else{
                //find the predecessor
                prev = cur->left;
                while(prev->right != NULL && prev->right != cur)
                    prev = prev->right;
                    
                if(prev->right == NULL){
                    //set the right child of the prev to current node
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    //Finish the left child tree, continue to right tree
                    prev->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
    
};