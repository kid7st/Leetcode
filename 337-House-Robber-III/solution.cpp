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
    
unordered_map<TreeNode*, int> robbedCount;
unordered_map<TreeNode*, int> unrobbedCount;
   
private:
    int dfsRob(TreeNode* root, bool robbed) {
        if(root == NULL)
            return 0;
            
        if(robbed && robbedCount.count(root) > 0)
            return robbedCount[root];
        if(!robbed && unrobbedCount.count(root) > 0)
            return unrobbedCount[root];
            
        if(robbed){
            robbedCount[root] = root->val + dfsRob(root->left, false) + dfsRob(root->right, false);
            return robbedCount[root];
        }else{
            unrobbedCount[root] = max(dfsRob(root->left, true), dfsRob(root->left, false)) + 
                        max(dfsRob(root->right, true), dfsRob(root->right, false));
            return unrobbedCount[root];
        }
    }
};