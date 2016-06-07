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
    int kthSmallest(TreeNode* root, int k) {
        int l = 0, r = 0;
        if(root->left != NULL){
            l = kthSmallest(root->left, k);
        }
        count++;
        if(count == k){
            return root->val;
        }
        if(root->right != NULL){
            r = kthSmallest(root->right, k);
        }
        return l + r;
    }
private:
    int count = 0;
};