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
        stack<TreeNode*> nodeStack;
        
        vector<int> res;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            res.push_back(node->val);
            
            if(node->right != NULL)
                nodeStack.push(node->right);
                
            if(node->left != NULL)
                nodeStack.push(node->left);
        }
        
        return res;
    }
};