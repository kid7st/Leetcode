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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return vector<TreeNode*>();
        return generateTrees(1, n);
    }
    
private:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> trees;
        if(start > end){
            trees.push_back(NULL);
            return trees;
        }
        
        for(int pivot = start; pivot <= end; pivot++){
            vector<TreeNode*> lefts = generateTrees(start, pivot - 1);
            vector<TreeNode*> rights = generateTrees(pivot + 1, end);
            for(TreeNode* left : lefts){
                for(TreeNode* right : rights){
                    TreeNode* root = new TreeNode(pivot);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        
        return trees;
    }
};