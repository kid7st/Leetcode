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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        build(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    void build(TreeNode* root, vector<vector<int>> &acc, int layer){
        if(!root) return;
        if(layer >= acc.size())
            acc.push_back(vector<int>{root->val});
        else
            acc[layer].push_back(root->val);
        
        build(root->left, acc, layer + 1);
        build(root->right, acc, layer + 1);
        return;
    }
};